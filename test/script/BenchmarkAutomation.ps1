param (
    [string[]]$appArguments,
    [int]$timeoutInMs = 3000 # Default timeout is 5 minutes
)

try {
    $argumentArray = $appArguments -split '\s+'
    # Start the process
    $process = Start-Process -FilePath ("../../bin/PartitionsGeneration.exe") -ArgumentList $argumentArray -PassThru -ErrorAction Sto
    # Wait for the process to finish or timeout
    if ($process.WaitForExit($timeoutInMs)) {
        Write-Host ($appArguments + " completed with exit code $($process.ExitCode)")
    } else {
        Write-Host ($appArguments + " timed out. Killing...")
        $process.Kill()
    }
}
catch {
    Write-Host "An error occurred: $_.Exception.Message"
}