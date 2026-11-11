# ---- Force UTF-8 everywhere so emoji + entities survive the HTTPS hop ----
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

function ConvertTo-HtmlSafe {
  param($Value)
  if ($null -eq $Value) { return '' }
  return ([string]$Value).Replace('&','&amp;').Replace('<','&lt;').Replace('>','&gt;').Replace('"','&quot;')
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

# ---- Inline pie-chart helper. Reads the PNGs produced by
# generate_ci_piecharts.py and returns a data:image/png;base64 URI so
# the chart renders directly in the email body (Power Automate does
# not auto-attach workflow artifacts). Returns $null on miss. ----
function Get-PieDataUri {
  param([string[]] $Candidates)
  foreach ($p in $Candidates) {
    if ($p -and (Test-Path $p)) {
      try {
        $bytes = [System.IO.File]::ReadAllBytes($p)
        return "data:image/png;base64," + [Convert]::ToBase64String($bytes)
      } catch { Write-Warning "Failed to inline ${p}: $_" }
    }
  }
  return $null
}
$testPieB64 = Get-PieDataUri @(
  $(if ($env:REPORT_DIR) { Join-Path $env:REPORT_DIR 'test_results_pie.png' } else { $null }),
  'test_results_pie.png'
)
$srsPieB64 = Get-PieDataUri @(
  $(if ($env:REPORT_DIR) { Join-Path $env:REPORT_DIR 'srs_results_pie.png' } else { $null }),
  'srs_results_pie.png'
)

# ---- Derived metrics for the health banner / progress bars ----
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
$totalSrs   = $srsPassedCnt + $srsFailedCnt + $srsErrorCnt
$testPassPct = if ($totalTests -gt 0) { [Math]::Round(($passedCount / $totalTests) * 100, 1) } else { 0 }
$srsPassPct  = if ($totalSrs   -gt 0) { [Math]::Round(($srsPassedCnt / $totalSrs)   * 100, 1) } else { 0 }
if     ($testPassPct -ge 90) { $bannerColor = "#16a34a"; $bannerLabel = "HEALTHY" }
elseif ($testPassPct -ge 70) { $bannerColor = "#d97706"; $bannerLabel = "DEGRADED" }
else                          { $bannerColor = "#dc2626"; $bannerLabel = "CRITICAL" }

# ---- Failure diagnosis: determine why the run failed (mirrors summarize step) ----
$failureCategory = ''
$failureReason   = ''
$upstreamRunUrl  = ''
$canCallGitHub = -not [string]::IsNullOrWhiteSpace($env:GITHUB_TOKEN) -and
                 -not [string]::IsNullOrWhiteSpace($env:GITHUB_API_URL) -and
                 -not [string]::IsNullOrWhiteSpace($env:GITHUB_REPOSITORY)
# Callers that already know the failure reason (e.g. sqt-build.yml diagnosing a
# build-all.yml failure by scraping job logs) can skip the outcome-based guesswork
# below entirely by passing it straight through.
if (-not [string]::IsNullOrWhiteSpace($env:FAILURE_CATEGORY_OVERRIDE)) {
  $failureCategory = ConvertTo-PlainText $env:FAILURE_CATEGORY_OVERRIDE
  $failureReason   = ConvertTo-PlainText $env:FAILURE_REASON_OVERRIDE
} elseif ($env:SUBMODULE_SYNC_OUTCOME  -eq 'failure') {
  $failureCategory = 'Infrastructure / Network'
  $failureReason   = 'Submodule sync failed. Gerrit host (gitgerrit.asux.aptiv.com) unreachable. Likely: VPN disconnected, DNS failure, or Gerrit down.'
} elseif ($env:REPO_INIT_OUTCOME     -eq 'failure') {
  $failureCategory = 'Setup / Environment'
  $failureReason   = 'Repo init or Python framework setup failed. Check runner Python installation and dependency availability.'
} elseif ($env:BUILD_DL_GH_OUTCOME   -eq 'failure') {
  $failureCategory = 'Build Artifact (GitHub)'
  $failureReason   = 'GitHub Actions artifact download failed. Verify upstream build run completed, artifact name is correct, and GH_ARTIFACT_TOKEN is set.'
  # Resolve the upstream build run URL so the team can jump straight to the failing build
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
    'Build Artifact*' { $bannerColor = '#b45309'; $bannerLabel = 'BUILD FAILURE' }
    'Test Execution'  { $bannerColor = '#dc2626'; $bannerLabel = 'TEST FAILURE'  }
    default           { $bannerColor = '#7c3aed'; $bannerLabel = 'INFRA FAILURE' }
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

# ---- Parse rotation matrix for schedule table ----
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

# ---- Shared metadata (Teams webhook retired -- GitHub Email is now the sole channel) ----
$jobType = ConvertTo-PlainText $env:JOB_TYPE
$family  = ConvertTo-PlainText $env:FAMILY
$runNum  = ConvertTo-PlainText $env:GITHUB_RUN_NUMBER
$sha = ConvertTo-PlainText $env:GITHUB_SHA
$commitShort = if ($sha.Length -ge 7) { $sha.Substring(0, 7) } else { $sha }

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
Write-Host "Links: run=$runUrl job=$jobUrl build=$buildOutputsUrl html=$htmlReportUrl"

# ---- HTML Email body ----
$dateStr = (Get-Date).ToString("dddd dd-MMMM-yyyy")
$htmlJobType   = ConvertTo-HtmlSafe $jobType
$htmlVariant   = ConvertTo-HtmlSafe $env:VARIANT
$htmlXcp       = ConvertTo-HtmlSafe $env:XCP
$htmlSha       = ConvertTo-HtmlSafe $sha
$htmlBranch    = ConvertTo-HtmlSafe $env:BRANCH
$htmlWorkflow  = ConvertTo-HtmlSafe $env:GITHUB_WORKFLOW
$htmlDate      = ConvertTo-HtmlSafe $dateStr
$htmlBanner    = ConvertTo-HtmlSafe $bannerLabel
$bannerHref    = if ($runUrl) { $runUrl } else { '' }

# Dark theme palette (using bgcolor attributes for Outlook compatibility)
$bodyBg='#1a1a2e'; $textColor='#e2e8f0'; $cardBg='#16213e'; $cardBorder='border:1px solid #334155;'
$linkColor='#60a5fa'; $dateHL='#93c5fd'; $sectionTitle='#93c5fd'; $subText='#94a3b8'
$labelColor='#94a3b8'; $variantColor='#c4b5fd'; $xcpColor='#fbbf24'; $commitColor='#22d3ee'
$passBg='#065f46'; $passText='#6ee7b7'; $failBg='#7f1d1d'; $failText='#fca5a5'
$skipBg='#713f12'; $skipText='#fde047'; $errBg='#581c87'; $errText='#e9d5ff'
$failTitle='#f87171'; $failValue='#f87171'; $noteText='#94a3b8'; $footerText='#94a3b8'
$badgeBg='#1e3a5f'; $badgeText='#93c5fd'; $greetText='color:#cbd5e1;'
$headerSubText='#93c5fd'; $headerVariant='#e9d5ff'; $headerXcp='#fde68a'
$todayRowBg='#1e3a5f'; $todayRowText='#93c5fd'
$altRow1='#16213e'; $altRow2='#1a1a2e'; $rowText='#cbd5e1'

# Build rotation schedule HTML rows -- always show full 7 days (bgcolor for Outlook)
$scheduleRows = ""
if ($rotationIsDaily -and $matrix.Count -gt 1) {
  for ($i = 0; $i -lt 7; $i++) {
    $idx = ($dayOfYear + $i) % $matrix.Count
    $combo = $matrix[$idx]
    if ($i -eq 0) {
      $dateLabel = "&#x25B6; Today ($($istNow.ToString('ddd, MMM dd')))"
      $rBgColor = $todayRowBg
      $rColor = "color:${todayRowText};font-weight:bold;"
    } else {
      $dateLabel = $istNow.AddDays($i).ToString('ddd, MMM dd')
      $rBgColor = if ($i % 2 -eq 0) { $altRow2 } else { $altRow1 }
      $rColor = "color:${rowText};"
    }
    $vSafe = ConvertTo-HtmlSafe $combo.variant
    $xSafe = ConvertTo-HtmlSafe $combo.xcp
    $scheduleRows += "<tr bgcolor='${rBgColor}'><td style='padding:6px 12px;${rColor}'>${dateLabel}</td><td style='padding:6px 12px;${rColor}'>${vSafe}</td><td style='padding:6px 12px;${rColor}'>${xSafe}</td></tr>"
  }
}

$scheduleBlock = ""
if ($scheduleRows) {
  $scheduleBlock = @"
<tr><td style="padding:15px 20px 0 20px;">
<table width="100%" cellpadding="0" cellspacing="0" border="0" style="border:1px solid #334155;">
<tr><td bgcolor="${bodyBg}" style="padding:12px;font-size:16px;font-weight:bold;color:${sectionTitle};">&#x1F4C5; Test Rotation Schedule (This Week)</td></tr>
<tr><td bgcolor="${cardBg}" style="padding:0;">
<table width="100%" cellpadding="8" cellspacing="0" border="0">
<tr bgcolor="#1e40af"><th align="left" style="color:#ffffff;font-size:13px;padding:8px 12px;">Date</th><th align="left" style="color:#ffffff;font-size:13px;padding:8px 12px;">Variant</th><th align="left" style="color:#ffffff;font-size:13px;padding:8px 12px;">XCP</th></tr>
${scheduleRows}
</table>
</td></tr>
</table>
</td></tr>
"@
}

# Pre-build HTML fragments that cannot use nested here-strings inside $emailHtml
$testNamesHtml = ''
if ($env:NEW_TEST_NAMES -and $newTestCount -gt 0) {
  $items = ($env:NEW_TEST_NAMES -split "`r?`n") | Where-Object { -not [string]::IsNullOrWhiteSpace($_) } | ForEach-Object {
    $safe = ConvertTo-HtmlSafe $_.Trim()
    "<li style='font-family:Consolas,monospace;font-size:12px;color:#fca5a5;padding:2px 0;'>$safe</li>"
  }
  if ($items) { $testNamesHtml = "<ul style='margin:6px 0 4px 20px;padding:0;'>$($items -join '')</ul>" }
}
$srsNamesHtml = ''
if ($env:NEW_SRS_NAMES -and $newSrsCount -gt 0) {
  $items = ($env:NEW_SRS_NAMES -split "`r?`n") | Where-Object { -not [string]::IsNullOrWhiteSpace($_) } | ForEach-Object {
    $safe = ConvertTo-HtmlSafe $_.Trim()
    "<li style='font-family:Consolas,monospace;font-size:12px;color:#fca5a5;padding:2px 0;'>$safe</li>"
  }
  if ($items) { $srsNamesHtml = "<ul style='margin:6px 0 4px 20px;padding:0;'>$($items -join '')</ul>" }
}
$failureDiagHtml = ""
if ($failureCategory) {
  $catSafe = ConvertTo-HtmlSafe $failureCategory
  $reasonSafe = (ConvertTo-HtmlSafe $failureReason) -replace "`r?`n", '<br/>'
  $failureDiagHtml = @"
<tr><td style='padding:15px 20px 0 20px;'>
<table width='100%' cellpadding='0' cellspacing='0' border='0' style='border:1px solid #dc2626;'>
<tr><td bgcolor='#7f1d1d' style='padding:10px 15px;font-size:16px;font-weight:bold;color:#fca5a5;'>&#x274C; Failure Diagnosis</td></tr>
<tr><td bgcolor='#450a0a' style='padding:14px 15px 8px 15px;'><span style='display:inline-block;background-color:#dc2626;color:#fef2f2;font-size:11px;font-weight:bold;letter-spacing:0.5px;text-transform:uppercase;padding:3px 10px;'>$catSafe</span></td></tr>
<tr><td bgcolor='#450a0a' style='padding:8px 15px 14px 15px;font-size:13px;color:#fcd5d5;line-height:1.5;'>$reasonSafe</td></tr>
</table>
</td></tr>
"@
}
$offlineRunnersHtml = ""
if ($offlineRunners.Count -gt 0) {
  $offlineList = ConvertTo-HtmlSafe ($offlineRunners -join ', ')
  $offlineRunnersHtml = "<tr><td style='padding:10px 20px 0 20px;'><table width='100%' cellpadding='10' cellspacing='0' border='0' style='border:1px solid #d97706;'><tr><td bgcolor='#713f12' style='font-size:14px;font-weight:bold;color:#fde047;'>&#x26A0; Offline Runner(s) Detected for this job: $offlineList</td></tr></table></td></tr>"
}
$cancelledRunsHtml = ""
if ($cancelledRuns.Count -gt 0) {
  $cancelList = (ConvertTo-ObjectArray $cancelledRuns | ForEach-Object { ConvertTo-HtmlSafe $_ }) -join '<br/>'
  $cancelledRunsHtml = "<tr><td style='padding:10px 20px 0 20px;'><table width='100%' cellpadding='10' cellspacing='0' border='0' style='border:1px solid #dc2626;'><tr><td bgcolor='#7f1d1d' style='font-size:14px;font-weight:bold;color:#fca5a5;'>&#x26D4; Auto-cancelled $($cancelledRuns.Count) stuck queued run(s)</td></tr><tr><td bgcolor='#450a0a' style='font-size:13px;color:#fcd5d5;'>$cancelList</td></tr></table></td></tr>"
}

$emailHtml = @"
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
</head>
<body style="margin:0;padding:0;" bgcolor="${bodyBg}">
<table width="100%" cellpadding="0" cellspacing="0" border="0" bgcolor="${bodyBg}">
<tr><td align="center" style="padding:16px;">
<table width="600" cellpadding="0" cellspacing="0" border="0" bgcolor="${cardBg}" style="font-family:Segoe UI,Arial,sans-serif;color:${textColor};">

<!-- Top Buttons -->
<tr><td bgcolor="${cardBg}" style="padding:20px;text-align:center;">
$(if ($runUrl) { "<a href='${runUrl}' style='display:inline-block;background-color:#3b82f6;color:#ffffff;padding:12px 24px;margin:4px;text-decoration:none;font-weight:bold;font-size:14px;'>This Run</a>" })
$(if ($jobUrl) { "<a href='${jobUrl}' style='display:inline-block;background-color:#1d4ed8;color:#ffffff;padding:12px 24px;margin:4px;text-decoration:none;font-weight:bold;font-size:14px;'>Workflow</a>" })
$(if ($buildOutputsUrl) { "<a href='${buildOutputsUrl}' style='display:inline-block;background-color:#7c3aed;color:#ffffff;padding:12px 24px;margin:4px;text-decoration:none;font-weight:bold;font-size:14px;'>Build Outputs</a>" })
$(if ($htmlReportUrl) { "<a href='${htmlReportUrl}' style='display:inline-block;background-color:#059669;color:#ffffff;padding:12px 24px;margin:4px;text-decoration:none;font-weight:bold;font-size:14px;'>HTML Report</a>" })
</td></tr>

<tr><td bgcolor="#1e40af" style="padding:20px;">
<h2 style="margin:0 0 8px 0;color:#ffffff;font-size:20px;">&#x1F680; Gen8 ${htmlJobType} Nightly Report</h2>
<p style="margin:0;color:${headerSubText};font-size:14px;"><strong style="color:${headerVariant};">${htmlVariant}</strong> &nbsp;|&nbsp; <strong style="color:${headerXcp};">${htmlXcp}</strong></p>
<table width="100%" cellpadding="0" cellspacing="0" border="0" style="margin-top:14px;"><tr><td align="center">
$(if ($bannerHref) { "<a href='${bannerHref}' style='text-decoration:none;'>" } else { '' })<table cellpadding="0" cellspacing="0" border="0"><tr><td bgcolor="${bannerColor}" style="padding:10px 24px;color:#ffffff;font-weight:bold;font-size:16px;letter-spacing:1px;">${htmlBanner}</td></tr></table>$(if ($bannerHref) { "</a>" } else { '' })
<p style="margin:6px 0 0 0;color:#c7d2fe;font-size:13px;">${testPassPct}% pass</p>
</td></tr></table>
</td></tr>

<!-- Greeting -->
<tr><td bgcolor="${cardBg}" style="padding:20px 20px 10px 20px;font-size:15px;color:${textColor};">
Hello Team,<br><br>
Test results from <strong style="color:#60a5fa;">${htmlWorkflow}</strong> nightly CI for <strong style="color:${dateHL};">${htmlDate}</strong>
</td></tr>

${failureDiagHtml}
${offlineRunnersHtml}
${cancelledRunsHtml}

<!-- Build Config -->
<tr><td style="padding:0 20px;">
<table width="100%" cellpadding="10" cellspacing="0" border="0" bgcolor="${cardBg}" style="border:1px solid #334155;margin-top:10px;">
<tr><td colspan="2" bgcolor="${bodyBg}" style="font-size:16px;font-weight:bold;color:${sectionTitle};">&#x1F527; Build Configuration</td></tr>
<tr><td style="color:${labelColor};font-size:14px;width:100px;">Job Type:</td><td style="font-size:14px;"><strong style="color:${variantColor};">${htmlJobType}</strong></td></tr>
<tr><td style="color:${labelColor};font-size:14px;">Variant:</td><td style="font-size:14px;"><strong style="color:${variantColor};">${htmlVariant}</strong></td></tr>
<tr><td style="color:${labelColor};font-size:14px;">XCP:</td><td style="font-size:14px;"><strong style="color:${xcpColor};">${htmlXcp}</strong></td></tr>
<tr><td style="color:${labelColor};font-size:14px;">Commit:</td><td style="font-size:12px;color:${commitColor};">${htmlSha}</td></tr>
<tr><td style="color:${labelColor};font-size:14px;">Branch:</td><td style="font-size:14px;"><strong style="color:${commitColor};">${htmlBranch}</strong></td></tr>
</table>
</td></tr>

<!-- Build Health -->
<tr><td style="padding:15px 20px 0 20px;">
<table width="100%" cellpadding="15" cellspacing="0" border="0" style="border:1px solid #334155;">
<tr><td bgcolor="${bodyBg}" align="center">
<p style="margin:0;font-size:11px;color:${labelColor};text-transform:uppercase;letter-spacing:1.5px;">BUILD HEALTH</p>
$(if ($bannerHref) { "<a href='${bannerHref}' style='text-decoration:none;'>" } else { '' })<p style="margin:8px 0;font-size:40px;font-weight:bold;color:${bannerColor};">${testPassPct}%</p>$(if ($bannerHref) { "</a>" } else { '' })
<p style="margin:0;font-size:13px;color:${subText};">${passedCount} / ${totalTests} tests pass</p>
</td></tr>
<tr><td bgcolor="${cardBg}" style="padding:10px 15px;">
<table width="100%" cellpadding="0" cellspacing="0" border="0">
<tr><td style="font-size:12px;color:${labelColor};">Tests</td><td align="right" style="font-size:12px;color:${labelColor};font-weight:bold;">${testPassPct}%</td></tr>
<tr><td colspan="2" style="padding:4px 0;"><table width="100%" cellpadding="0" cellspacing="0" border="0" bgcolor="#334155"><tr><td width="${testPassPct}%" bgcolor="${bannerColor}" style="height:8px;font-size:1px;">&nbsp;</td><td style="height:8px;font-size:1px;">&nbsp;</td></tr></table></td></tr>
<tr><td style="font-size:12px;color:${labelColor};padding-top:8px;">SRS</td><td align="right" style="font-size:12px;color:${labelColor};font-weight:bold;padding-top:8px;">${srsPassPct}%</td></tr>
<tr><td colspan="2" style="padding:4px 0;"><table width="100%" cellpadding="0" cellspacing="0" border="0" bgcolor="#334155"><tr><td width="${srsPassPct}%" bgcolor="#3b82f6" style="height:8px;font-size:1px;">&nbsp;</td><td style="height:8px;font-size:1px;">&nbsp;</td></tr></table></td></tr>
</table>
</td></tr>
</table>
</td></tr>

<!-- Test Summary -->
<tr><td style="padding:15px 20px 0 20px;">
<table width="100%" cellpadding="0" cellspacing="0" border="0" style="border:1px solid #334155;">
<tr><td bgcolor="${badgeBg}" align="center" style="padding:10px;font-weight:bold;color:${badgeText};font-size:14px;">Test Summary</td></tr>
<tr><td bgcolor="${cardBg}" style="padding:10px;">
$(if ($testPieB64) { "<table width='100%' cellpadding='0' cellspacing='0' border='0'><tr><td align='center' style='padding-bottom:10px;'><img src='${testPieB64}' alt='Test Results' width='240' style='max-width:100%;'/></td></tr></table>" })
<table width="260" cellpadding="8" cellspacing="4" border="0" align="center">
<tr><td bgcolor="${passBg}" style="color:${passText};font-weight:bold;font-size:14px;">PASSED<span style="float:right;">${passedCount}</span></td></tr>
<tr><td bgcolor="${failBg}" style="color:${failText};font-weight:bold;font-size:14px;">FAILED<span style="float:right;">${failedCount}</span></td></tr>
<tr><td bgcolor="${skipBg}" style="color:${skipText};font-weight:bold;font-size:14px;">SKIPPED<span style="float:right;">${skippedCount}</span></td></tr>
<tr><td bgcolor="${errBg}" style="color:${errText};font-weight:bold;font-size:14px;">ERROR<span style="float:right;">${errorCount}</span></td></tr>
</table>
</td></tr>
</table>
</td></tr>

<!-- SRS Summary -->
<tr><td style="padding:15px 20px 0 20px;">
<table width="100%" cellpadding="0" cellspacing="0" border="0" style="border:1px solid #334155;">
<tr><td bgcolor="${badgeBg}" align="center" style="padding:10px;font-weight:bold;color:${badgeText};font-size:14px;">SRS Summary</td></tr>
<tr><td bgcolor="${cardBg}" style="padding:10px;">
$(if ($srsPieB64) { "<table width='100%' cellpadding='0' cellspacing='0' border='0'><tr><td align='center' style='padding-bottom:10px;'><img src='${srsPieB64}' alt='SRS Results' width='240' style='max-width:100%;'/></td></tr></table>" })
<table width="260" cellpadding="8" cellspacing="4" border="0" align="center">
<tr><td bgcolor="${passBg}" style="color:${passText};font-weight:bold;font-size:14px;">PASSED<span style="float:right;">${srsPassedCnt}</span></td></tr>
<tr><td bgcolor="${failBg}" style="color:${failText};font-weight:bold;font-size:14px;">FAILED<span style="float:right;">${srsFailedCnt}</span></td></tr>
<tr><td bgcolor="${errBg}" style="color:${errText};font-weight:bold;font-size:14px;">ERROR<span style="float:right;">${srsErrorCnt}</span></td></tr>
</table>
</td></tr>
</table>
</td></tr>

<!-- Reports Buttons -->
<tr><td style="padding:15px 20px 0 20px;">
<table width="100%" cellpadding="0" cellspacing="0" border="0" style="border:1px solid #334155;">
<tr><td bgcolor="${bodyBg}" style="padding:12px;font-size:16px;font-weight:bold;color:${sectionTitle};">&#x1F4CA; Reports &amp; Links</td></tr>
<tr><td bgcolor="${cardBg}" align="center" style="padding:10px 15px 15px 15px;">
$(if ($runUrl) { "<a href='${runUrl}' style='display:inline-block;background-color:#3b82f6;color:#ffffff;padding:10px 16px;margin:3px;text-decoration:none;font-weight:bold;font-size:12px;'>This Run</a>" })
$(if ($jobUrl) { "<a href='${jobUrl}' style='display:inline-block;background-color:#1d4ed8;color:#ffffff;padding:10px 16px;margin:3px;text-decoration:none;font-weight:bold;font-size:12px;'>Workflow</a>" })
$(if ($buildOutputsUrl) { "<a href='${buildOutputsUrl}' style='display:inline-block;background-color:#7c3aed;color:#ffffff;padding:10px 16px;margin:3px;text-decoration:none;font-weight:bold;font-size:12px;'>Build Outputs</a>" })
$(if ($htmlReportUrl) { "<a href='${htmlReportUrl}' style='display:inline-block;background-color:#059669;color:#ffffff;padding:10px 16px;margin:3px;text-decoration:none;font-weight:bold;font-size:12px;'>HTML Report</a>" })
$(if ($grafanaUrl) { "<a href='${grafanaUrl}' style='display:inline-block;background-color:#6366f1;color:#ffffff;padding:10px 16px;margin:3px;text-decoration:none;font-weight:bold;font-size:12px;'>Platform Health</a>" })
</td></tr>
</table>
</td></tr>

<!-- New Failures -->
<tr><td style="padding:15px 20px 0 20px;">
<table width="100%" cellpadding="12" cellspacing="0" border="0" style="border:1px solid #334155;">
<tr><td colspan="2" bgcolor="${bodyBg}" style="font-size:16px;font-weight:bold;color:${failTitle};">&#x26D4; New Failures</td></tr>
<tr><td bgcolor="${cardBg}" style="font-size:15px;color:${textColor};">Test Cases: <strong style="color:${failValue};">${newTestCount}</strong>${testNamesHtml}</td></tr>
<tr><td bgcolor="${cardBg}" style="font-size:15px;color:${textColor};">SRS Requirements: <strong style="color:${failValue};">${newSrsCount}</strong>${srsNamesHtml}</td></tr>
<tr><td bgcolor="${cardBg}" style="font-size:12px;color:${noteText};border-top:1px solid #334155;padding-top:10px;">Delta = new failures vs previous run</td></tr>
</table>
</td></tr>

${scheduleBlock}

<!-- Footer -->
<tr><td bgcolor="${cardBg}" style="padding:20px;font-size:14px;color:${textColor};">
Best Regards,<br>
<b style="color:#60a5fa;">Gen8 ${htmlJobType} CICD Mail</b>
</td></tr>

</table>
</td></tr>
</table>
</body>
</html>
"@

$emailSubject = "Gen8 $jobType ($family) Nightly Job #$runNum | $bannerLabel ($testPassPct%) | $(ConvertTo-PlainText $env:VARIANT) [$(ConvertTo-PlainText $env:XCP)]"

# Recipient list from workflow input. Comma, semicolon or newline separated.
$rawRecipients = ConvertTo-PlainText $env:EMAIL_RECIPIENTS
$candidateAddrs = @($rawRecipients -split '[;,\s]+' | Where-Object { $_ })
$recipients = @($candidateAddrs | Where-Object { $_ -match '^[^@\s]+@[^@\s]+\.[^@\s]+$' })
$rejectedAddrs = @($candidateAddrs | Where-Object { $_ -notmatch '^[^@\s]+@[^@\s]+\.[^@\s]+$' })

# Recipient resolution is logged unconditionally -- a silent skip here was
# previously indistinguishable from a successful send in the run log.
Write-Host "EMAIL_RECIPIENTS raw length : $($rawRecipients.Length) char(s)"
Write-Host "Recipients accepted ($($recipients.Count)): $($recipients -join ', ')"
if ($rejectedAddrs.Count -gt 0) {
  Write-Host "::warning::Rejected $($rejectedAddrs.Count) malformed recipient token(s): $($rejectedAddrs -join ' | '). Use bare addresses (a@b.com), not 'Name <a@b.com>'."
}

# ---- Send bool: lets callers turn the email off entirely without touching recipients ----
$sendEmail = -not ($env:SEND_EMAIL -ieq 'false')
if (-not $sendEmail) {
  Write-Host "SEND_EMAIL=false; skipping notification email."
  return
}
if ($recipients.Count -eq 0) {
  if ([string]::IsNullOrWhiteSpace($rawRecipients)) {
    Write-Host "::error::EMAIL_RECIPIENTS is empty -- no notification email sent. Check the caller's 'email-recipients' input / ADVRADAR_EMAIL_RECIPIENTS repo variable."
  } else {
    Write-Host "::error::EMAIL_RECIPIENTS contained no valid addresses -- no notification email sent. Rejected: $($rejectedAddrs -join ' | ')"
  }
  return
}

# ---- Dispatch via the Aptiv internal SMTP relay (no auth, no Power Automate) ----
# Power Automate / Teams webhooks are blocked by admin policy, so this is now
# the only notification channel. The HTML body above already covers every case
# that used to live in the Teams Adaptive Card (build/infra failures, offline
# runners, cancelled runs, new-failure lists, schedule) -- sent for every run,
# not just runs with real test results.
#
# Dispatch goes through tools/CI/send_ci_email.py (Python smtplib), which uses
# the same mechanism as the working Runner Health report: STARTTLS is negotiated
# when the relay advertises it. System.Net.Mail.SmtpClient never does that on
# port 25 (EnableSsl defaults to false) and fails with a generic
# "Failure sending mail." That .NET path is kept only as a fallback for runners
# without Python.
$smtpServer = if ([string]::IsNullOrWhiteSpace($env:SMTP_SERVER)) { 'bulkmail.aptiv.com' } else { $env:SMTP_SERVER }
$smtpPort   = Get-EnvInt 'SMTP_PORT' 25
$emailFrom  = if ([string]::IsNullOrWhiteSpace($env:EMAIL_FROM)) { 'Gen8 CICD Mail <no_reply@aptiv.com>' } else { $env:EMAIL_FROM }

function Get-PythonCommand {
  foreach ($candidate in @(@('python', @()), @('python3', @()), @('py', @('-3')))) {
    $exe = $candidate[0]
    if (Get-Command $exe -ErrorAction SilentlyContinue) {
      return [pscustomobject]@{ Exe = $exe; Args = $candidate[1] }
    }
  }
  return $null
}

function Send-ViaPython {
  param([string]$Script, [string[]]$Recipients, [string]$Subject, [string]$BodyHtml)

  if (-not (Test-Path -LiteralPath $Script)) {
    Write-Host "::warning::Python sender not found at $Script"
    return $false
  }
  $py = Get-PythonCommand
  if (-not $py) {
    Write-Host "::warning::No python interpreter on PATH -- cannot use the smtplib dispatcher."
    return $false
  }

  $bodyFile = Join-Path ([System.IO.Path]::GetTempPath()) "ci_email_body_$PID.html"
  try {
    [System.IO.File]::WriteAllText($bodyFile, $BodyHtml, (New-Object System.Text.UTF8Encoding $false))
    $prev = @{
      EMAIL_TO        = $env:EMAIL_TO
      EMAIL_SUBJECT   = $env:EMAIL_SUBJECT
      EMAIL_BODY_FILE = $env:EMAIL_BODY_FILE
      EMAIL_FROM      = $env:EMAIL_FROM
      SMTP_SERVER     = $env:SMTP_SERVER
      SMTP_PORT       = $env:SMTP_PORT
      PAGES_URL       = $env:PAGES_URL
    }
    $env:EMAIL_TO        = ($Recipients -join ',')
    $env:EMAIL_SUBJECT   = $Subject
    $env:EMAIL_BODY_FILE = $bodyFile
    $env:EMAIL_FROM      = $emailFrom
    $env:SMTP_SERVER     = $smtpServer
    $env:SMTP_PORT       = "$smtpPort"
    $env:PAGES_URL       = ''
    try {
      $pyOut = & $py.Exe @($py.Args + @($Script)) 2>&1
      $pyOut | ForEach-Object { Write-Host "[send_ci_email] $_" }
      if ($LASTEXITCODE -eq 0) { return $true }
      # stderr and stdout interleave unpredictably, so pick the ERROR: line explicitly.
      $lines = @($pyOut | ForEach-Object { "$_" } | Where-Object { $_ -match '\S' })
      $reason = @($lines | Where-Object { $_ -match '^\s*ERROR' }) | Select-Object -Last 1
      if (-not $reason) { $reason = $lines | Select-Object -Last 1 }
      if (-not $reason) { $reason = '(no output captured)' }
      Write-Host "::warning::Python SMTP dispatch failed (exit $LASTEXITCODE) -- $reason"
      return $false
    } finally {
      foreach ($k in $prev.Keys) {
        if ($null -eq $prev[$k]) {
          Remove-Item -Path "Env:$k" -ErrorAction SilentlyContinue
        } else {
          Set-Item -Path "Env:$k" -Value $prev[$k] -ErrorAction SilentlyContinue
        }
      }
    }
  } catch {
    Write-Host "::warning::Python sender threw: $($_.Exception.Message)"
    return $false
  } finally {
    Remove-Item -LiteralPath $bodyFile -Force -ErrorAction SilentlyContinue
  }
}

function Send-ViaDotNet {
  param([string[]]$Recipients, [string]$Subject, [string]$BodyHtml)

  # Try plaintext first, then STARTTLS -- relays differ on which they accept.
  foreach ($useSsl in @($false, $true)) {
    $mail = $null; $smtp = $null
    try {
      $mail = New-Object System.Net.Mail.MailMessage
      $mail.From = $emailFrom
      foreach ($addr in $Recipients) { $mail.To.Add($addr) }
      $mail.Subject = $Subject
      $mail.SubjectEncoding = [System.Text.Encoding]::UTF8
      $mail.Body = $BodyHtml
      $mail.BodyEncoding = [System.Text.Encoding]::UTF8
      $mail.IsBodyHtml = $true

      $smtp = New-Object System.Net.Mail.SmtpClient($smtpServer, $smtpPort)
      $smtp.EnableSsl = $useSsl
      $smtp.Timeout = 30000
      $smtp.Send($mail)
      return $true
    } catch {
      # SmtpException hides the real cause in InnerException -- unwrap it all.
      $detail = @(); $ex = $_.Exception
      while ($ex) { $detail += "$($ex.GetType().Name): $($ex.Message)"; $ex = $ex.InnerException }
      Write-Host "::warning::.NET SMTP send (EnableSsl=$useSsl) failed -- $($detail -join ' <- ')"
    } finally {
      if ($mail) { $mail.Dispose() }
      if ($smtp) { $smtp.Dispose() }
    }
  }
  return $false
}

# $PSScriptRoot is empty when the body is dot-sourced rather than run as a file.
$ciScriptRoot = if ([string]::IsNullOrWhiteSpace($PSScriptRoot)) { Join-Path (Get-Location).Path 'tools\CI' } else { $PSScriptRoot }
$pythonSender = Join-Path $ciScriptRoot 'send_ci_email.py'
Write-Host "Sending via ${smtpServer}:${smtpPort} to: $($recipients -join ', ')"

# Preflight: distinguishes "relay unreachable from this runner" (network/VPN)
# from "relay rejected the message" (protocol/policy).
try {
  $probe = New-Object System.Net.Sockets.TcpClient
  if ($probe.ConnectAsync($smtpServer, $smtpPort).Wait(10000) -and $probe.Connected) {
    Write-Host "SMTP preflight: TCP connect to ${smtpServer}:${smtpPort} OK."
  } else {
    Write-Host "::warning::SMTP preflight: cannot reach ${smtpServer}:${smtpPort} from this runner (VPN/firewall/DNS?)."
  }
  $probe.Close()
} catch {
  Write-Host "::warning::SMTP preflight failed for ${smtpServer}:${smtpPort} -- $($_.Exception.Message)"
}

$sent = Send-ViaPython -Script $pythonSender -Recipients $recipients -Subject $emailSubject -BodyHtml $emailHtml
if (-not $sent) {
  Write-Host "::warning::Python dispatch unavailable/failed; falling back to System.Net.Mail."
  $sent = Send-ViaDotNet -Recipients $recipients -Subject $emailSubject -BodyHtml $emailHtml
}

if ($sent) {
  Write-Host "Notification email sent to: $($recipients -join ', ')"
} else {
  # Surface on the run summary -- this used to be a silent Write-Warning.
  Write-Host "::error::Notification email could not be sent via ${smtpServer}:${smtpPort} to $($recipients -join ', '). See the SMTP warnings above."
}

if ($env:GITHUB_STEP_SUMMARY) {
  try {
    $status = if ($sent) { 'SENT' } else { 'FAILED' }
    $subjCell = $emailSubject -replace '\|', '\|'
    "### Notification email: $status`n`n| Field | Value |`n|---|---|`n| Relay | ``${smtpServer}:${smtpPort}`` |`n| Recipients | $($recipients -join ', ') |`n| Subject | $subjCell |" |
      Out-File -FilePath $env:GITHUB_STEP_SUMMARY -Append -Encoding utf8
  } catch {
    Write-Host "::warning::Could not append to the run summary: $($_.Exception.Message)"
  }
}
