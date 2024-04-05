param (
    [string]$appArguments = "-mode int -alg Tree -visit Counter -rout out.txt -n 10000 -k 3000",
    [int]$timeoutInMs = 3600000 # Default timeout is 1 hour
)

try {
    Write-Output $appArguments
    $argumentArray = $appArguments -split '\s+'
    $processStartInfo = New-Object System.Diagnostics.ProcessStartInfo
    $processStartInfo.FileName = "../../bin/PartitionsGeneration.exe"
    $processStartInfo.Arguments = $argumentArray
    $processStartInfo.RedirectStandardOutput = $true
    $processStartInfo.UseShellExecute = $false
    $processStartInfo.WorkingDirectory = "../../bin"
    $process = [System.Diagnostics.Process]::Start($processStartInfo)
    $output = $process.StandardOutput.ReadToEnd()
    # Wait for the process to finish or timeout
    if ($process.WaitForExit($timeoutInMs)) {
        Write-Host ($appArguments + " completed with exit code $($process.ExitCode)")
    } else {
        Write-Host ($appArguments + " timed out. Killing...")
        $process.Kill()
    }
    Write-Output $output
}
catch {
    Write-Host "An error occurred: $_.Exception.Message"
}