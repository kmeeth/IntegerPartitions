param (
    [int[]]$N_int = @(100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000, 600000, 70000, 80000, 90000, 100000),
    [int[]]$K_int = @(3, 4, 5, 6, 7, 8, 9, 10, 15, 20, 25, 30, 40, 50, 60, 75, 100, 150, 200, 250, 300, -2 , -3, -4, 0),
    [int[]]$N_set = @(14, 16, 18, 20, 22, 24, 26, 28, 30, 35, 40, 50, 60),
    [int[]]$K_set = @(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 25, 30, -1, -2, -3, 0),
    [System.Object[]]$algs = @(@("int", "Tree"), @("int", "Conjugation"), @("int", "SimpleBacktracking"), @("set", "Filter"), @("set", "SimpleBacktracking")),
    [int]$maxProcesses = 96,
    [int]$maxMinutes = 12 * 60
)

# List to keep track of running jobs
[System.Diagnostics.Process[]]$script:jobs = @()
# Start moment
$script:startMoment = Get-Date

# Function to start a new job
function Start-NewJob {
    param(
        [string]$appArguments
    )
    Write-Output $appArguments
    $script:jobs += Start-Process -FilePath "powershell.exe" -ArgumentList "-File", "AppTimedWrapper.ps1", "-appArguments", "`"$appArguments`"" -PassThru
}

# Check if any jobs have completed and remove them from the list
function Check-JobCompletion {
    Write-Output $script:jobs
    $script:jobs = $script:jobs | Where-Object { -not $_.HasExited }
    Write-Output "becomes"
    Write-Output $script:jobs
    Write-Output "###################"
}

function Iterate
{
    param(
        [System.Object]$a,
        [int]$n,
        [int]$k
    )
    if($k -eq 0) {
        $k = $n / 2
    }
    if($k -lt 0) {
        $k = $k + $n
    }
    if($k -gt $n) {
        return
    }

    # Check if the maximum number of processes is reached
    while ($script:jobs.Count -ge $maxProcesses) {
        Start-Sleep -Seconds 5
        $currentMoment = Get-Date
        if($script:startMoment.AddMinutes($maxMinutes) -lt $currentMoment) {
            Write-Output "TIME IS PAST KILLING ALL"
            foreach($job in $script:jobs){
                if(-not $job.HasExited){
                    $job.Terminate()
                }
            }
            exit
        }

        Check-JobCompletion
    }

    $mode = $a[0]
    $alg = $a[1]
    $rout = $alg + "_" + $n + "_" + $k + "." + $mode

    # Start a new job with your program and arguments
    $arguments = ("-mode " + $mode + " -alg " + $alg + " -visit Benchmark -rout " + $rout + " -n " + $n + " -k " + $k)
    Start-NewJob -appArguments $arguments
}

# Main loop to manage starting new jobs
foreach($a in $algs) {
    if($a[0] -eq "int") {
        foreach($n in $N_int) {
            foreach($k in $K_int) {
                Iterate $a $n $k
            }
        }
    }
    else {
        foreach($n in $N_set) {
            foreach($k in $K_set) {
                Iterate $a $n $k
            }
        }
    }
}
# Join all
while ($script:jobs.Count -gt 0) {
    Start-Sleep -Seconds 5
    Check-JobCompletion
}