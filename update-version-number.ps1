# Path to the INI file
$iniFile = ".\Config\DefaultGame.ini"

if (-not (Test-Path $iniFile)) {
    Write-Error "File '$iniFile' not found."
    exit 1
}

# Get the current commit SHA
$commitSha = (git rev-parse HEAD).Trim()

if (-not $commitSha) {
    Write-Error "Unable to determine current Git commit SHA."
    exit 1
}

# Get the most recent tag beginning with 'v'
$tag = (git describe --tags --abbrev=0 --match "v*" 2>$null).Trim()

if (-not $tag) {
    Write-Error "No Git tag beginning with 'v' was found."
    exit 1
}

Write-Host "Using tag:        $tag"
Write-Host "Using commit SHA: $commitSha"

# Read the file
$content = Get-Content $iniFile

# Replace the ProjectVersion line
$content = $content -replace '^ProjectVersion=.*$', "ProjectVersion=$tag-$commitSha"

# Write the updated file
Set-Content -Path $iniFile -Value $content -Encoding UTF8

Write-Host "Updated ProjectVersion in '$iniFile'."