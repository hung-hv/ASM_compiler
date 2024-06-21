# Get the path of the current script
$scriptPath = $MyInvocation.MyCommand.Path

# Define the path to the build directory
$buildDir = Split-Path -Parent $scriptPath

$buildScriptPath = Join-Path -Path $buildDir -ChildPath "build.ps1"

# Get the path of the current script
$scriptPath = $MyInvocation.MyCommand.Path

# Check if the directory exists
if (Test-Path $buildDir) {
    # Get all items in the build directory
    $items = Get-ChildItem -Path $buildDir

    # Loop through each item
    foreach ($item in $items) {
        # If the item is not the current script, remove it
        if ($item.FullName -ne $scriptPath -and $item.FullName -ne $buildScriptPath) {
            Remove-Item -Path $item.FullName -Recurse -Force
        }
    }
} else {
    Write-Output "The directory $buildDir does not exist."
}