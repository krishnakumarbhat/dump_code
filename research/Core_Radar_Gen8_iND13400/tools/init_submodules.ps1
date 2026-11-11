<#
.SYNOPSIS
    Initialize / update the Git submodules of this repository.

.DESCRIPTION
    Reads .gitmodules, shows the configured submodules and lets you pick which
    ones to initialize. Recovers automatically when the commit pinned by this
    repository no longer exists on the remote (for example after a repository
    migration) by falling back to the tip of the tracked branch.

.PARAMETER Submodule
    One or more submodule paths or name fragments to initialize. Skips the menu.

.PARAMETER All
    Initialize every submodule listed in .gitmodules. Skips the menu.

.PARAMETER Remote
    Always use the tip of the tracked branch instead of the commit pinned by
    this repository.

.EXAMPLE
    pwsh tools/init_submodules.ps1

.EXAMPLE
    pwsh tools/init_submodules.ps1 -Submodule sip, Python_Framework

.EXAMPLE
    pwsh tools/init_submodules.ps1 -All
#>
[CmdletBinding()]
param(
    [string[]]$Submodule,
    [switch]$All,
    [switch]$Remote
)

$ErrorActionPreference = 'Stop'

function Write-Step { param([string]$Message) Write-Host "[INFO]    $Message" }
function Write-Ok { param([string]$Message) Write-Host "[SUCCESS] $Message" -ForegroundColor Green }
function Write-Warn { param([string]$Message) Write-Host "[WARNING] $Message" -ForegroundColor Yellow }
function Write-Fail { param([string]$Message) Write-Host "[ERROR]   $Message" -ForegroundColor Red }

function Invoke-Git {
    param([string[]]$Arguments)
    # Native stderr surfaces as an ErrorRecord, which would terminate under
    # $ErrorActionPreference = 'Stop' before the exit code can be inspected.
    $previous = $ErrorActionPreference
    $ErrorActionPreference = 'Continue'
    try {
        $output = & git @Arguments 2>&1
        $code = $LASTEXITCODE
    }
    finally {
        $ErrorActionPreference = $previous
    }
    return [pscustomobject]@{
        ExitCode = $code
        Output   = ($output | Out-String).TrimEnd()
    }
}

function Get-UpdateArgs {
    param([string]$Path, [bool]$UseRemote)
    $arguments = @('submodule', 'update', '--init')
    if ($UseRemote) { $arguments += @('--remote', '--force') }
    return $arguments + @('--progress', '--', $Path)
}

# -c options reach the submodule via GIT_CONFIG_PARAMETERS, so these also disable
# the LFS smudge filter for the nested checkout.
$lfsOff = @('-c', 'filter.lfs.smudge=', '-c', 'filter.lfs.process=', '-c', 'filter.lfs.required=false')

# --- Locate the repository root -------------------------------------------------
$repoRoot = (& git rev-parse --show-toplevel 2>$null)
if ($LASTEXITCODE -ne 0 -or [string]::IsNullOrWhiteSpace($repoRoot)) {
    Write-Fail 'Not inside a Git repository.'
    exit 1
}
$repoRoot = $repoRoot.Trim().Replace('/', [IO.Path]::DirectorySeparatorChar)
Push-Location $repoRoot

try {
    $gitmodules = Join-Path $repoRoot '.gitmodules'
    if (-not (Test-Path $gitmodules)) {
        Write-Fail "No .gitmodules found at $gitmodules"
        exit 1
    }

    # --- Parse .gitmodules ------------------------------------------------------
    $entries = @{}
    foreach ($line in (& git config --file .gitmodules --get-regexp '^submodule\.')) {
        if ($line -match '^submodule\.(?<name>.+)\.(?<key>path|url|branch|ignore)\s+(?<value>.*)$') {
            $name = $Matches['name']
            if (-not $entries.ContainsKey($name)) {
                $entries[$name] = [ordered]@{ Name = $name; Path = $null; Url = $null; Branch = $null }
            }
            switch ($Matches['key']) {
                'path' { $entries[$name].Path = $Matches['value'] }
                'url' { $entries[$name].Url = $Matches['value'] }
                'branch' { $entries[$name].Branch = $Matches['value'] }
            }
        }
    }

    $modules = @($entries.Values | Where-Object { $_.Path } | ForEach-Object { [pscustomobject]$_ } | Sort-Object Path)
    if ($modules.Count -eq 0) {
        Write-Fail 'No submodules are configured in .gitmodules.'
        exit 1
    }

    foreach ($m in $modules) {
        $marker = Join-Path (Join-Path $repoRoot $m.Path) '.git'
        $m | Add-Member -NotePropertyName Initialized -NotePropertyValue (Test-Path $marker)
    }

    # --- Select which submodules to process -------------------------------------
    $selected = @()

    if ($All) {
        $selected = $modules
    }
    elseif ($Submodule) {
        foreach ($wanted in $Submodule) {
            $match = @($modules | Where-Object { $_.Path -like "*$wanted*" -or $_.Name -like "*$wanted*" })
            if ($match.Count -eq 0) {
                Write-Fail "No submodule matches '$wanted'."
                exit 1
            }
            $selected += $match
        }
        $selected = @($selected | Sort-Object Path -Unique)
    }
    else {
        Write-Host ''
        Write-Host '========================================================='
        Write-Host '   Git submodules configured in this repository'
        Write-Host '========================================================='
        for ($i = 0; $i -lt $modules.Count; $i++) {
            $m = $modules[$i]
            $state = if ($m.Initialized) { 'initialized' } else { 'not initialized' }
            $branch = if ($m.Branch) { "branch: $($m.Branch)" } else { 'pinned commit' }
            Write-Host ("  [{0}] {1}" -f ($i + 1), $m.Path)
            Write-Host ("      {0}  |  {1}  |  {2}" -f $m.Url, $branch, $state)
        }
        Write-Host ''
        Write-Host '  [a] all submodules      [q] quit'
        Write-Host ''

        $answer = (Read-Host 'Select submodules to initialize (e.g. 1,3 or a)').Trim()
        if ($answer -eq '' -or $answer -match '^(q|quit|exit)$') {
            Write-Step 'Nothing selected. Exiting.'
            exit 0
        }
        if ($answer -match '^(a|all)$') {
            $selected = $modules
        }
        else {
            foreach ($token in ($answer -split '[,\s]+' | Where-Object { $_ })) {
                $index = 0
                if (-not [int]::TryParse($token, [ref]$index) -or $index -lt 1 -or $index -gt $modules.Count) {
                    Write-Fail "'$token' is not a valid selection."
                    exit 1
                }
                $selected += $modules[$index - 1]
            }
            $selected = @($selected | Sort-Object Path -Unique)
        }
    }

    # --- Initialize -------------------------------------------------------------
    $results = @()

    foreach ($m in $selected) {
        Write-Host ''
        Write-Host '---------------------------------------------------------'
        Write-Step "Submodule : $($m.Path)"
        Write-Step "Remote    : $($m.Url)"
        if ($m.Branch) { Write-Step "Branch    : $($m.Branch)" }

        # Push the URL from .gitmodules into .git/config so clones made before a
        # host migration stop talking to the old server.
        $sync = Invoke-Git @('submodule', 'sync', '--', $m.Path)
        if ($sync.ExitCode -ne 0) {
            Write-Fail "Failed to sync submodule URL.`n$($sync.Output)"
            $results += [pscustomobject]@{ Path = $m.Path; Status = 'failed'; Detail = 'submodule sync failed' }
            continue
        }

        $usedRemoteTip = $false
        $skippedLfs = $false

        if ($Remote) {
            $usedRemoteTip = $true
            $update = Invoke-Git (Get-UpdateArgs -Path $m.Path -UseRemote $true)
        }
        else {
            $update = Invoke-Git (Get-UpdateArgs -Path $m.Path -UseRemote $false)

            if ($update.ExitCode -ne 0 -and $update.Output -match 'not our ref|did not contain') {
                Write-Warn 'The commit pinned by this repository does not exist on the remote.'
                Write-Warn 'Falling back to the tip of the tracked branch.'
                $usedRemoteTip = $true
                $update = Invoke-Git (Get-UpdateArgs -Path $m.Path -UseRemote $true)
            }
        }

        if ($update.ExitCode -ne 0 -and $update.Output -match 'smudge filter lfs|git-lfs filter-process|batch response') {
            Write-Warn 'Git LFS could not download the large files for this submodule.'
            Write-Warn 'Retrying the checkout with the LFS smudge filter disabled.'
            $skippedLfs = $true
            $update = Invoke-Git ($lfsOff + (Get-UpdateArgs -Path $m.Path -UseRemote $usedRemoteTip))
        }

        if ($update.ExitCode -ne 0) {
            Write-Fail "Failed to initialize the submodule.`n$($update.Output)"
            $results += [pscustomobject]@{ Path = $m.Path; Status = 'failed'; Detail = 'submodule update failed' }
            continue
        }

        $sha = (& git -C $m.Path rev-parse HEAD).Trim()

        if ($usedRemoteTip) {
            Write-Ok "Checked out $sha (tip of the tracked branch)."
            Write-Warn "This differs from the commit recorded in the parent repository."
            Write-Warn "To fix it for everyone: git add $($m.Path) && git commit"
            $results += [pscustomobject]@{ Path = $m.Path; Status = 'recovered'; Detail = $sha }
        }
        else {
            Write-Ok "Checked out $sha."
            $results += [pscustomobject]@{ Path = $m.Path; Status = 'ok'; Detail = $sha }
        }

        if ($skippedLfs) {
            Write-Warn 'LFS-tracked files are still pointer stubs in this submodule.'
            Write-Warn "Add aptv.ghe.com to your .netrc, then run: git -C $($m.Path) lfs pull"
        }

        Write-Step 'Active remote:'
        & git -C $m.Path remote -v
    }

    # --- Summary ----------------------------------------------------------------
    Write-Host ''
    Write-Host '========================================================='
    Write-Host '   Summary'
    Write-Host '========================================================='
    foreach ($r in $results) {
        $colour = switch ($r.Status) {
            'ok' { 'Green' }
            'recovered' { 'Yellow' }
            default { 'Red' }
        }
        Write-Host ("  {0,-10} {1}" -f $r.Status, $r.Path) -ForegroundColor $colour
    }
    Write-Host ''

    if ($results | Where-Object { $_.Status -eq 'recovered' }) {
        Write-Warn 'Some submodules were recovered against the tracked branch instead of the recorded commit.'
        Write-Warn 'Note that Core_Radar_Python_Framework uses "ignore = all", so git status will not show it.'
    }

    if ($results | Where-Object { $_.Status -eq 'failed' }) { exit 1 }
    exit 0
}
finally {
    Pop-Location
}
