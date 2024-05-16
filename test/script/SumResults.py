N_int = [100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000, 600000, 70000, 80000, 90000, 100000]
K_int = [3, 4, 5, 6, 7, 8, 9, 10, 15, 20, 25, 30, 40, 50, 60, 75, 100, 150, 200, 250, 300, -2 , -3, -4]
N_set = [14, 16, 18, 20, 22, 24, 26, 28, 30, 35, 40, 50, 60]
K_set = [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 25, 30, -1, -2, -3]
alg_int = ["SimpleBacktracking", "Conjugation", "Tree"]
alg_set = ["SimpleBacktracking", "Filter"]

map_int = {}
for alg in alg_int:
    for N in N_int:
        for K in K_int:
            if K > N:
                continue
            if K < 0:
                K = N + K
            with open(f"../output/{alg}_{N}_{K}.int") as f:
                line = f.readline()
                if len(line) == 0:
                    map_int[(alg, N, K)] = "CRASH"
                    continue
                line = line.strip("\n")
                if line != "TIME":
                    line = line[:-2]
                map_int[(alg, N, K)] = line

map_set = {}
for alg in alg_set:
    for N in N_set:
        for K in K_set:
            if K > N:
                continue
            if K < 0:
                K = N + K
            with open(f"../output/{alg}_{N}_{K}.set") as f:
                line = f.readline()
                if len(line) == 0:
                    map_set[(alg, N, K)] = "CRASH"
                    continue
                line = line.strip("\n")
                if line != "TIME":
                    line = line[:-2]
                map_set[(alg, N, K)] = line

for alg in alg_int:
    with open(f"../output/{alg}_results.int", "w") as f:
        f.write("N/K,")
        for K in K_int:
            f.write(f"{K},")
        f.write("\n")
        for N in N_int:
            f.write(f"{N},")
            for K in K_int:
                if K > N:
                    f.write("#,")
                    continue
                if K < 0:
                    K = N + K
                f.write(f"{map_int[(alg, N, K)]},")
            f.write("\n")

for alg in alg_set:
    with open(f"../output/{alg}_results.set", "w") as f:
        f.write("N/K,")
        for K in K_set:
            f.write(f"{K},")
        f.write("\n")
        for N in N_set:
            f.write(f"{N},")
            for K in K_set:
                if K > N:
                    f.write("#,")
                    continue
                if K < 0:
                    K = N + K
                f.write(f"{map_set[(alg, N, K)]},")
            f.write("\n")