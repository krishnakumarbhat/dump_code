# ============================================================
# send_teams_card_notification.ps1
#
# Standalone Adaptive Card sender for a Power Automate / Teams
# incoming webhook. Split out from send_email_notification.ps1
# (which now only sends the HTML report email via SMTP, because
# Power Automate / Teams webhooks are currently blocked by admin
# policy). Drop this script back into a workflow step -- with the
# same env var contract this file previously used -- to re-enable
# Teams notifications once the policy is lifted. No other files
# need to change.
#
# Required:
#   TEAMS_URL   Power Automate / Teams incoming webhook URL.
#               Missing or non-http(s) -> skipped silently.
# Optional toggle:
#   SEND_TEAMS  'false' to skip explicitly even if TEAMS_URL is set. Default true.
#
# Metrics:      PASSED FAILED SKIPPED ERRORS SRS_PASSED SRS_FAILED SRS_ERRORS
#               NEW_TEST NEW_SRS NEW_TEST_NAMES NEW_SRS_NAMES (newline-separated)
# Labels:       JOB_TYPE FAMILY VARIANT XCP BRANCH
# Links:        RUN_URL JOB_URL BUILD_OUTPUTS_URL HTML_ARTIFACT_URL GRAFANA_DASHBOARD
# Schedule:     MATRIX_JSON ROTATION ('daily' | 'fixed')
# Failure diagnosis (self-computed, same as before):
#   SUBMODULE_SYNC_OUTCOME REPO_INIT_OUTCOME BUILD_DL_GH_OUTCOME TEST_OUTCOME
#   GH_ARTIFACT_RUN_ID GH_ARTIFACT_WORKFLOW GH_ARTIFACT_BRANCH
# Runner health (self-computed via GitHub API, same as before):
#   GITHUB_TOKEN GITHUB_API_URL GITHUB_SERVER_URL GITHUB_REPOSITORY RUNNER_LABELS_JSON
# ============================================================

# ---- Force UTF-8 everywhere so emoji survive the HTTPS hop ----
[Console]::OutputEncoding = New-Object System.Text.UTF8Encoding $false
$OutputEncoding           = New-Object System.Text.UTF8Encoding $false
$ErrorActionPreference    = 'Continue'

function Get-EnvInt {
  param([string]$Name, [int]$Default = 0)
  $raw = [Environment]::GetEnvironmentVariable($Name)
  if ([string]::IsNullOrWhiteSpace($raw)) { return $Default }
  $parsed = 0
  if ([int]::TryParse($raw, [ref]$parsed)) { return $parsed }
  Write-Warning "Non-integer env $Name='$raw'; using $Default."
  return $Default
}

function ConvertTo-PlainText {
  param($Value)
  if ($null -eq $Value) { return '' }
  return ([string]$Value).Trim()
}

function Test-HttpUrl {
  param([string]$Url)
  if ([string]::IsNullOrWhiteSpace($Url)) { return $false }
  return ($Url -match '^https?://\S+$')
}

function ConvertTo-ObjectArray {
  param($Value)
  if ($null -eq $Value) { return @() }
  if ($Value -is [System.Array]) { return @($Value) }
  return @($Value)
}

if (-not (Test-HttpUrl $env:TEAMS_URL)) {
  Write-Warning "TEAMS_URL missing or not http(s); Teams notification skipped."
  return
}
if ($env:SEND_TEAMS -ieq 'false') {
  Write-Host "SEND_TEAMS=false; skipping Teams notification."
  return
}

# ---- Emoji characters (single BMP code points only -- no VS16, which
# renders as a stray '?' in some Teams clients). ConvertTo-Json will
# emit them as proper \uXXXX escapes regardless. ----
$cross = [char]0x274C    # U+274C cross mark
$check = [char]0x2705    # U+2705 check mark
$warn  = [char]0x26A0    # U+26A0 warning (no VS16 -- single code point)

# ---- Derived metrics for the health banner ----
$passedCount   = Get-EnvInt 'PASSED'
$failedCount   = Get-EnvInt 'FAILED'
$skippedCount  = Get-EnvInt 'SKIPPED'
$errorCount    = Get-EnvInt 'ERRORS'
$srsPassedCnt  = Get-EnvInt 'SRS_PASSED'
$srsFailedCnt  = Get-EnvInt 'SRS_FAILED'
$srsErrorCnt   = Get-EnvInt 'SRS_ERRORS'
$newTestCount  = Get-EnvInt 'NEW_TEST'
$newSrsCount   = Get-EnvInt 'NEW_SRS'
$totalTests = $passedCount + $failedCount + $skippedCount + $errorCount
$testPassPct = if ($totalTests -gt 0) { [Math]::Round(($passedCount / $totalTests) * 100, 1) } else { 0 }
if     ($testPassPct -ge 90) { $bannerLabel = "HEALTHY" }
elseif ($testPassPct -ge 70) { $bannerLabel = "DEGRADED" }
else                          { $bannerLabel = "CRITICAL" }

# ---- Failure diagnosis: determine why the run failed (mirrors summarize step) ----
$failureCategory = ''
$failureReason   = ''
$upstreamRunUrl  = ''
$canCallGitHub = -not [string]::IsNullOrWhiteSpace($env:GITHUB_TOKEN) -and
                 -not [string]::IsNullOrWhiteSpace($env:GITHUB_API_URL) -and
                 -not [string]::IsNullOrWhiteSpace($env:GITHUB_REPOSITORY)
if     ($env:SUBMODULE_SYNC_OUTCOME  -eq 'failure') {
  $failureCategory = 'Infrastructure / Network'
  $failureReason   = 'Submodule sync failed. Gerrit host (gitgerrit.asux.aptiv.com) unreachable. Likely: VPN disconnected, DNS failure, or Gerrit down.'
} elseif ($env:REPO_INIT_OUTCOME     -eq 'failure') {
  $failureCategory = 'Setup / Environment'
  $failureReason   = 'Repo init or Python framework setup failed. Check runner Python installation and dependency availability.'
} elseif ($env:BUILD_DL_GH_OUTCOME   -eq 'failure') {
  $failureCategory = 'Build Artifact (GitHub)'
  $failureReason   = 'GitHub Actions artifact download failed. Verify upstream build run completed, artifact name is correct, and GH_ARTIFACT_TOKEN is set.'
  try {
    $bHdrs = @{ Authorization="Bearer $env:GITHUB_TOKEN"; Accept="application/vnd.github+json"; 'X-GitHub-Api-Version'='2022-11-28' }
    if ($env:GH_ARTIFACT_RUN_ID -and (Test-HttpUrl $env:GITHUB_SERVER_URL) -and $env:GITHUB_REPOSITORY) {
      $upstreamRunUrl = "$env:GITHUB_SERVER_URL/$env:GITHUB_REPOSITORY/actions/runs/$env:GH_ARTIFACT_RUN_ID"
    } elseif ($env:GH_ARTIFACT_WORKFLOW -and $canCallGitHub) {
      $branch = if ($env:GH_ARTIFACT_BRANCH) { [uri]::EscapeDataString($env:GH_ARTIFACT_BRANCH) } else { 'main' }
      $wf = [uri]::EscapeDataString($env:GH_ARTIFACT_WORKFLOW)
      $uri = "$env:GITHUB_API_URL/repos/$env:GITHUB_REPOSITORY/actions/workflows/$wf/runs?branch=$branch&per_page=1&status=completed"
      $resp = Invoke-RestMethod -Uri $uri -Headers $bHdrs -Method Get -TimeoutSec 30 -ErrorAction Stop
      $runs = ConvertTo-ObjectArray $resp.workflow_runs
      if ($runs.Count -gt 0) {
        $r = $runs[0]
        if (Test-HttpUrl $r.html_url) { $upstreamRunUrl = [string]$r.html_url }
        $failureReason += " Last upstream run: #$($r.run_number) ($($r.conclusion))."
      }
    }
  } catch { Write-Warning "Could not resolve upstream build run URL: $_" }
} elseif ($env:TEST_OUTCOME           -eq 'failure') {
  $failureCategory = 'Test Execution'
  $failureReason   = 'Run_Test_Cases.bat exited non-zero. Review test logs in the workflow run for the root cause.'
} elseif ($totalTests -eq 0) {
  $failureCategory = 'Unknown'
  $failureReason   = 'No test results produced. An earlier step may have failed silently. Check the workflow run log for the first red step.'
}

# Differentiate banner label by failure category when there are zero results
if ($failureCategory -and $totalTests -eq 0) {
  switch -Wildcard ($failureCategory) {
    'Build Artifact*' { $bannerLabel = 'BUILD FAILURE' }
    'Test Execution'  { $bannerLabel = 'TEST FAILURE'  }
    default           { $bannerLabel = 'INFRA FAILURE' }
  }
}

# ---- Runner offline check + cancel stuck queued runs (SWE6 labels only) ----
$offlineRunners = @()
$cancelledRuns  = @()
$apiHdrs = @{ Authorization="Bearer $env:GITHUB_TOKEN"; Accept="application/vnd.github+json"; 'X-GitHub-Api-Version'='2022-11-28' }
try {
  $runnerLabels = @()
  if (-not [string]::IsNullOrWhiteSpace($env:RUNNER_LABELS_JSON)) {
    $runnerLabels = ConvertTo-ObjectArray ($env:RUNNER_LABELS_JSON | ConvertFrom-Json) | ForEach-Object { "$_" }
  }
  if (-not $canCallGitHub) { throw "GitHub API context missing; skip runner health." }
  $runnersResp = Invoke-RestMethod -Uri "$env:GITHUB_API_URL/repos/$env:GITHUB_REPOSITORY/actions/runners?per_page=100" -Headers $apiHdrs -Method Get -TimeoutSec 30 -ErrorAction Stop
  foreach ($r in (ConvertTo-ObjectArray $runnersResp.runners)) {
    if ($r.status -ne 'offline') { continue }
    $rLabels = @(ConvertTo-ObjectArray $r.labels | ForEach-Object { $_.name })
    if ($runnerLabels | Where-Object { $rLabels -contains $_ }) {
      if ($r.name) { $offlineRunners += [string]$r.name }
    }
  }
} catch {
  # GITHUB_TOKEN cannot list repo self-hosted runners (403 Resource not
  # accessible by integration). Skip without failing the notification.
  $msg = "$_"
  if ($msg -notmatch '403|Resource not accessible') {
    Write-Warning "Runner health check skipped: $_"
  } else {
    Write-Host "Runner health check skipped (GITHUB_TOKEN cannot list runners)."
  }
}

if ($offlineRunners.Count -gt 0) {
  try {
    $cutoff   = [DateTimeOffset]::UtcNow.AddDays(-1)
    $runsResp = Invoke-RestMethod -Uri "$env:GITHUB_API_URL/repos/$env:GITHUB_REPOSITORY/actions/runs?status=queued&per_page=50" -Headers $apiHdrs -Method Get -TimeoutSec 30 -ErrorAction Stop
    foreach ($run in (ConvertTo-ObjectArray $runsResp.workflow_runs)) {
      $created = [DateTimeOffset]::MinValue
      if (-not [DateTimeOffset]::TryParse([string]$run.created_at, [ref]$created)) { continue }
      if ($created -lt $cutoff) {
        try {
          Invoke-RestMethod -Uri "$env:GITHUB_API_URL/repos/$env:GITHUB_REPOSITORY/actions/runs/$($run.id)/cancel" -Headers $apiHdrs -Method Post -TimeoutSec 30 -ErrorAction Stop
          $cancelledRuns += "#$($run.run_number) $($run.name)"
        } catch { Write-Warning "Cancel run $($run.id) failed: $_" }
      }
    }
  } catch { Write-Warning "Cancel stuck runs skipped: $_" }
}

# ---- Parse rotation matrix + build next-day schedule text ----
$matrix = @()
try {
  if (-not [string]::IsNullOrWhiteSpace($env:MATRIX_JSON)) {
    $matrix = ConvertTo-ObjectArray ($env:MATRIX_JSON | ConvertFrom-Json)
  }
} catch {
  Write-Warning "Invalid MATRIX_JSON; schedule omitted: $_"
  $matrix = @()
}
try {
  $istNow = [System.TimeZoneInfo]::ConvertTimeBySystemTimeZoneId([DateTime]::UtcNow, "India Standard Time")
} catch {
  Write-Warning "IST timezone unavailable; using local time."
  $istNow = [DateTime]::Now
}
$dayOfYear = $istNow.DayOfYear
$rotationIsDaily = ($env:ROTATION -ine 'fixed')

$nextDaysList = ""
if ($rotationIsDaily -and $matrix.Count -gt 1) {
  for ($i = 1; $i -lt [Math]::Min(4, $matrix.Count); $i++) {
    $idx = ($dayOfYear + $i) % $matrix.Count
    $combo = $matrix[$idx]
    $d = $istNow.AddDays($i).ToString('ddd MMM dd')
    $nextDaysList += "${d}: $($combo.variant) [$($combo.xcp)]`n`n"
  }
} else {
  $nextDaysList = "(fixed run $([char]0x2014) no rotation)"
}

# ---- Adaptive Card (TextBlock-only, Power Automate compatible) ----
$jobType = ConvertTo-PlainText $env:JOB_TYPE
$family  = ConvertTo-PlainText $env:FAMILY
$runNum  = ConvertTo-PlainText $env:GITHUB_RUN_NUMBER
$title = "Gen8 $jobType ($family) Nightly Job #$runNum"
$sha = ConvertTo-PlainText $env:GITHUB_SHA
$commitShort = if ($sha.Length -ge 7) { $sha.Substring(0, 7) } else { $sha }

if     ($failureCategory -and $totalTests -eq 0) { $statusText = "$cross $bannerLabel";                   $statusColor = "Attention" }
elseif ($testPassPct -ge 90)                       { $statusText = "$check HEALTHY ($testPassPct% pass)";  $statusColor = "Good" }
elseif ($testPassPct -ge 70)                       { $statusText = "$warn DEGRADED ($testPassPct% pass)";  $statusColor = "Warning" }
elseif ($totalTests -gt 0)                         { $statusText = "$cross CRITICAL ($testPassPct% pass)"; $statusColor = "Attention" }
else                                               { $statusText = "$warn NO RESULTS";                     $statusColor = "Warning" }

$cardBody = @(
  @{ type="TextBlock"; size="Large"; weight="Bolder"; color="Accent"; text=$title }
  @{ type="TextBlock"; weight="Bolder"; color=$statusColor; text=$statusText }
  @{
    type  = "FactSet"
    separator = $true
    facts = @(
      @{ title="Branch";       value=(ConvertTo-PlainText $env:BRANCH) }
      @{ title="Variant";      value=(ConvertTo-PlainText $env:VARIANT) }
      @{ title="XCP";          value=(ConvertTo-PlainText $env:XCP) }
      @{ title="Job Type";     value=$jobType }
      @{ title="Family";       value=$family }
      @{ title="Run #";        value="#$runNum" }
      @{ title="Short Commit"; value=$commitShort }
      @{ title="Full SHA";     value=$sha }
    )
  }
  @{ type="TextBlock"; wrap=$true; color="Good";      text="$check Tests PASSED: $passedCount" }
  @{ type="TextBlock"; wrap=$true; color="Attention"; text="$cross Tests FAILED: $failedCount  |  Errors: $errorCount" }
  @{ type="TextBlock"; wrap=$true; color="Warning";   text="$warn Tests SKIPPED: $skippedCount" }
  @{ type="TextBlock"; wrap=$true; color="Good";      text="$check SRS: $srsPassedCnt passed / $srsFailedCnt failed / $srsErrorCnt errors" }
  @{ type="TextBlock"; wrap=$true; isSubtle=$true; separator=$true;
     text="**New Failures:** $newTestCount test / $newSrsCount SRS" }
  @{ type="TextBlock"; wrap=$true; separator=$true; size="Small"; weight="Bolder"; text="Upcoming Schedule:" }
  @{ type="TextBlock"; wrap=$true; size="Small"; isSubtle=$true; text=$nextDaysList }
)

# ---- New failure names (top-10 actual test/SRS IDs from platform-health delta) ----
if ($env:NEW_TEST_NAMES) {
  $tItems = ($env:NEW_TEST_NAMES -split "`r?`n") | ForEach-Object { $_.Trim() } | Where-Object { $_ }
  if ($tItems) {
    $cardBody += @{ type="TextBlock"; wrap=$true; separator=$true; size="Small"; weight="Bolder"; color="Attention"; text="New Failed Tests:" }
    $tLines = ($tItems | ForEach-Object { "$([char]0x2022) $_" }) -join "`n"
    $cardBody += @{ type="TextBlock"; wrap=$true; size="Small"; fontType="Monospace"; text=$tLines }
  }
}
if ($env:NEW_SRS_NAMES) {
  $sItems = ($env:NEW_SRS_NAMES -split "`r?`n") | ForEach-Object { $_.Trim() } | Where-Object { $_ }
  if ($sItems) {
    $cardBody += @{ type="TextBlock"; wrap=$true; separator=$true; size="Small"; weight="Bolder"; color="Attention"; text="New Failed SRS IDs:" }
    $sLines = ($sItems | ForEach-Object { "$([char]0x2022) $_" }) -join "`n"
    $cardBody += @{ type="TextBlock"; wrap=$true; size="Small"; fontType="Monospace"; text=$sLines }
  }
}

# ---- Failure diagnosis block (shown when infra/build failure caused zero results) ----
if ($failureCategory) {
  $cardBody += @{ type="TextBlock"; wrap=$true; separator=$true; weight="Bolder"; color="Attention";
                  text="$cross Failure Diagnosis" }
  $cardBody += @{ type="TextBlock"; wrap=$true; color="Attention";
                  text="**Category:** $failureCategory" }
  $cardBody += @{ type="TextBlock"; wrap=$true; isSubtle=$true; text=$failureReason }
  if ($upstreamRunUrl) {
    $cardBody += @{ type="TextBlock"; wrap=$true; color="Warning";
                    text="[View Upstream Build Run ->]($upstreamRunUrl)" }
  }
}

# ---- Offline runner warning (shown when matching runners are currently offline) ----
if ($offlineRunners.Count -gt 0) {
  $offlineList = $offlineRunners -join ', '
  $cardBody += @{ type="TextBlock"; wrap=$true; separator=$true; color="Warning";
                  text="$warn Offline runner(s) detected for this job: $offlineList" }
}

# ---- Cancelled stuck queued runs ----
if ($cancelledRuns.Count -gt 0) {
  $cancelList = $cancelledRuns -join ' | '
  $cardBody += @{ type="TextBlock"; wrap=$true; separator=$true; color="Attention";
                  text="$([char]0x26D4) Auto-cancelled $($cancelledRuns.Count) stuck queued run(s): $cancelList" }
}

# Canonical URLs. JOB_URL = workflow definition. RUN_URL = this run.
# BUILD_OUTPUTS_URL = upstream build-all run that produced firmware.
$runUrl = if (Test-HttpUrl $env:RUN_URL) { $env:RUN_URL } elseif ((Test-HttpUrl $env:GITHUB_SERVER_URL) -and $env:GITHUB_REPOSITORY -and $env:GITHUB_RUN_ID) { "$env:GITHUB_SERVER_URL/$env:GITHUB_REPOSITORY/actions/runs/$env:GITHUB_RUN_ID" } else { '' }
$jobUrl = if (Test-HttpUrl $env:JOB_URL) { $env:JOB_URL } else { '' }
$buildOutputsUrl = if (Test-HttpUrl $env:BUILD_OUTPUTS_URL) { $env:BUILD_OUTPUTS_URL } else { '' }
if (-not $buildOutputsUrl -and $env:GH_ARTIFACT_RUN_ID -and (Test-HttpUrl $env:GITHUB_SERVER_URL) -and $env:GITHUB_REPOSITORY) {
  $buildOutputsUrl = "$env:GITHUB_SERVER_URL/$env:GITHUB_REPOSITORY/actions/runs/$env:GH_ARTIFACT_RUN_ID"
}
$htmlReportUrl = if (Test-HttpUrl $env:HTML_ARTIFACT_URL) { $env:HTML_ARTIFACT_URL } elseif ($env:GH_ARTIFACT_UPLOADED -eq 'true' -and (Test-HttpUrl $env:GH_ARTIFACT_URL)) { $env:GH_ARTIFACT_URL } else { '' }
$grafanaUrl = if (Test-HttpUrl $env:GRAFANA_DASHBOARD) { $env:GRAFANA_DASHBOARD } else { '' }

$links = @()
if ($runUrl)          { $links += "[This Run]($runUrl)" }
if ($jobUrl)          { $links += "[Workflow]($jobUrl)" }
if ($buildOutputsUrl) { $links += "[Build Outputs]($buildOutputsUrl)" }
if ($htmlReportUrl)   { $links += "[HTML Report]($htmlReportUrl)" }
if ($grafanaUrl)      { $links += "[Platform Health]($grafanaUrl)" }
if ($links.Count -gt 0) {
  $cardBody += @{ type="TextBlock"; wrap=$true; text=($links -join " | ") }
}

$cardActions = @()
if ($runUrl)          { $cardActions += @{ type="Action.OpenUrl"; title="This Run";       url=$runUrl } }
if ($jobUrl)          { $cardActions += @{ type="Action.OpenUrl"; title="Workflow";       url=$jobUrl } }
if ($buildOutputsUrl) { $cardActions += @{ type="Action.OpenUrl"; title="Build Outputs";  url=$buildOutputsUrl } }
if ($htmlReportUrl)   { $cardActions += @{ type="Action.OpenUrl"; title="HTML Report";    url=$htmlReportUrl } }
Write-Host "Links: run=$runUrl job=$jobUrl build=$buildOutputsUrl html=$htmlReportUrl"

$cardContent = @{
  type = "AdaptiveCard"
  '$schema' = "http://adaptivecards.io/schemas/adaptive-card.json"
  version = "1.4"
  body = @(ConvertTo-ObjectArray $cardBody)
}
if ($cardActions -and @($cardActions).Count -gt 0) {
  $cardContent.actions = @(ConvertTo-ObjectArray $cardActions)
}

# Serialize as an object then wrap it in [] so PS 5.1 ConvertTo-Json
# cannot collapse a single-element attachments array. Power Automate
# reads first(triggerBody()?['attachments'])?['content'].
$attachmentJson = ([ordered]@{ contentType = "application/vnd.microsoft.card.adaptive"; content = $cardContent } | ConvertTo-Json -Depth 20 -Compress)
if ([string]::IsNullOrWhiteSpace($attachmentJson) -or $attachmentJson.TrimStart()[0] -ne '{') {
  Write-Warning "Adaptive Card JSON invalid; Teams notification skipped."
  return
}
$json = "{`"type`":`"message`",`"attachments`":[$attachmentJson]}"

try {
  # PowerShell 5.1's Invoke-RestMethod sends string -Body as ISO-8859-1
  # by default, which silently mangles emoji / supplementary-plane
  # characters to '?'. Encode as UTF-8 bytes and declare the charset
  # explicitly so glyphs survive the wire.
  $jsonBytes = [System.Text.Encoding]::UTF8.GetBytes($json)
  Invoke-RestMethod -Uri $env:TEAMS_URL -Method Post -ContentType 'application/json; charset=utf-8' -Body $jsonBytes -TimeoutSec 60 | Out-Null
  Write-Host "Teams notification sent."
} catch {
  Write-Warning "Teams notification failed: $_"
}
