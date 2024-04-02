param (
    [int[]]$N_int = @(100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000, 600000, 70000, 80000, 90000, 100000),
    [int[]]$K_int = @(3, 4, 5, 6, 7, 8, 9, 10, 15, 20, 25, 30, 40, 50, 60, 75, 100, 150, 200, 250, 300, -2 , -3, -4, 0),
    [int[]]$N_set = @(14, 16, 18, 20, 22, 24, 26, 28, 30, 35, 40, 50, 60),
    [int[]]$K_set = @(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 25, 30, -1, -2, -3, 0.5),
    [System.Object[]]$algs = @(@("int", "Tree"), @("int", "Conjugation"), @("int", "SimpleBacktracking"), @("set", "Filter"), @("set", "SimpleBacktracking")),
    [int]$maxProcesses = 1
)

# List to keep track of running jobs
$jobs = @()

# Function to start a new job
function Start-NewJob {
    param(
        [string]$program,
        [string]$arguments
    )

    $job = Start-Job -ScriptBlock {
        param($program, $arguments)
        & $program $arguments
    } -ArgumentList $program, $arguments

    $jobs += $job
}

# Check if any jobs have completed and remove them from the list
function Check-JobCompletion {
    $completedJobs = $jobs | Where-Object { $_.State -eq 'Completed' }
    foreach ($completedJob in $completedJobs) {
        $jobs.Remove($completedJob) | Out-Null
        $completedJob | Remove-Job
    }
}

# Main loop to manage starting new jobs
foreach($a in $algs) {
    if($a[0] -eq "int") {
        foreach($n in $N_int) {
            foreach($k in $K_int) {
                $k_actual = $k
                if($k -eq 0) {
                    $k_actual = $n / 2
                }
                if($k -lt 0){
                    $k_actual = $k + $n
                }
                Write-Output ("" + $n + ", " + $k_actual)

                # Check if the maximum number of processes is reached
                while ($jobs.Count -ge $maxProcesses) {
                    Start-Sleep -Seconds 5
                    Check-JobCompletion
                }

                $mode = $a[0]
                $alg = $a[1]
                $rout = "../test/output/" + $alg + "_" + $n + "_" + $k_actual + "." + $mode



                # Start a new job with your program and arguments
                $program = "../../bin/PartitionGeneration.exe"
                $arguments = ("-mode " + $mode + " -alg " + $alg + " -visit Counter -rout " + $rout + " -n " + $n + " -k " + $k_actual)
                Start-NewJob -program $program -arguments $arguments
            }
        }
    }
    else {
        foreach($n in $N_set) {
            foreach($k in $K_set) {
                $k_actual = $k
                if($k -eq 0) {
                    $k_actual = $n / 2
                }
                if($k -lt 0){
                    $k_actual = $k + $n
                }
                Write-Output ("" + $n + ", " + $k_actual)

                # Check if the maximum number of processes is reached
                while ($jobs.Count -ge $maxProcesses) {
                    Start-Sleep -Seconds 5
                    Check-JobCompletion
                }

                $mode = $a[0]
                $alg = $a[1]
                $rout = "../test/output/" + $alg + "_" + $n + "_" + $k_actual + "." + $mode



                # Start a new job with your program and arguments
                $program = "../../bin/PartitionGeneration.exe"
                $arguments = ("-mode " + $mode + " -alg " + $alg + " -visit Counter -rout " + $rout + " -n " + $n + " -k " + $k_actual)
                Start-NewJob -program $program -arguments $arguments
            }
        }
    }

}