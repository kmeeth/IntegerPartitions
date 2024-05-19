import sys
import threading
from functools import cache

threading.stack_size(4096 * 10000)
sys.setrecursionlimit(1<<31-1)


@cache
def partition(n, k):
    if k == 0 and n == 0:
        return 1
    if k == n:
        return 1
    if n <= 0 or k <= 0:
        return 0
    return partition(n - k, k) + partition(n - 1, k - 1)


def main():
    N = [100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000, 600000, 70000, 80000, 90000, 100000]
    K = [3, 4, 5, 6, 7, 8, 9, 10, 15, 20, 25, 30, 40, 50, 60, 75, 100, 150, 200, 250, 300, -2 , -3, -4]

    with open("../results/partitionCount.int", mode="a+") as file:
        file.write(f" ,")
    for k in K:
        with open("../results/partitionCount.int", mode="a+") as file:
            file.write(f"{k},")
    with open("../results/partitionCount.int", mode="a+") as file:
        file.write("\n")
    for n in N:
        with open("../results/partitionCount.int", mode="a+") as file:
            file.write(f"{n},")
        for k in K:
            k_actual = k
            if k_actual < 0:
                k_actual += n
            elif k_actual == 0.5:
                k_actual = n // 2
            with open("../results/partitionCount.int", mode="a+") as file:
                file.write(f"{partition(n, k_actual)},")
        with open("../results/partitionCount.int", mode="a+") as file:
            file.write("\n")


if __name__ == "__main__":
    thread = threading.Thread(target=main)
    thread.start()