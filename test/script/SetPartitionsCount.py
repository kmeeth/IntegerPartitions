import sys
import threading
from functools import cache

threading.stack_size(4096 * 10000)
sys.setrecursionlimit(2**31-1)


@cache
def partition(n, k):
    if n == k:
        return 1
    if k * n == 0:
        return 0
    return k * partition(n - 1, k) + partition(n - 1, k - 1)


def main():
    N = [14, 16, 18, 20, 22, 24, 26, 28, 30, 35, 40, 50]
    K = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20, -1, -2, -3, 0.5]

    for k in K:
        for n in N:
            with open("../output/partitionCount.set", mode="a") as file:
                k_actual = k
                if k_actual < 0:
                    k_actual += n
                elif k_actual == 0.5:
                    k_actual = n // 2
                file.write(f"{partition(n, k_actual)} ")
        with open("../output/partitionCount.set", mode="a") as file:
            file.write("\n")


if __name__ == "__main__":
    thread = threading.Thread(target=main)
    thread.start()