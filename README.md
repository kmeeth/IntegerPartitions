# MANUAL #
## Section 1 : The benchmarking scripts
In order to run a set of benchmarks, use the script `AutoBenchmark.ps1`, located in `test/script`. It takes arrays of `n` and `k` to generate partitions for, but the default values are just fine. The same goes for algorithms used. The parameters of interest are:
* `$maxProcesses` - default is 96, as that is the number of cores we are expected to use. Tweak if necessary.
* `$maxMinutes` - default is `12 * 60 = 720 minutes = 12 hours`. This is the time that the whole benchmarking process is allowed to run. Tweak if necessary. **Attention: There is a small problem with the script that does not let it close all the processes after the
`$maxMinutes` limit has expired, and currently the powershell scripts need to be closed manually. This is generally easy to do, but if it is a problem, set the `$maxMinutes` to one hour less, as that will make sure that everything is clean in time.**

This will generate outputs in `test/output`, named after each `(n, k, algorithm)` triplet evaluated. Examples that timed out will have `TIME` written in their files. Those that are empty have either crashed (memory problems) or forcefully closed.
Those with the `.int` suffix are associated with integer partitions, while the `.set` suffix indicates set partitioning.

The default timeout for a single pair is `1 * 60 * 60 * 1000 = 3600000ms = 1 hour`. Change in the `AppTimedWrapper.ps1` script directly if necessary.

## Section 2 : The PartitionsGeneration.exe
There is most likely no need to run the application directly for benchmarking purposes, as the scripts do a better job at that. If running directly is necessary, consult the `src/main.cpp` documentation comment that explains the various command line arguments used by the 
program. 
