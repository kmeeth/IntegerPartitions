param (
    [string]$appArguments = "-mode int -alg Tree -visit Counter -rout out.txt -n 1 -k 1",
    [int]$timeoutInMs = 3600000 # Default timeout is 1 hour
)

try {
    Write-Output $appArguments
    Write-Output $timeoutInMs
    $argumentArray = $appArguments -split '\s+'
    $processStartInfo = New-Object System.Diagnostics.ProcessStartInfo
    $processStartInfo.FileName = "../../bin/PartitionsGeneration.exe"
    $processStartInfo.Arguments = $argumentArray
    $processStartInfo.RedirectStandardOutput = $true
    $processStartInfo.UseShellExecute = $false
    $processStartInfo.WorkingDirectory = "../../bin"
    $process = [System.Diagnostics.Process]::Start($processStartInfo)
    #Wait for the process to finish or timeout
    if ($process.WaitForExit($timeoutInMs)) {
        $output = $process.StandardOutput.ReadToEnd()
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