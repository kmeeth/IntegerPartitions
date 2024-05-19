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
    N = [14, 16, 18, 20, 22, 24, 26, 28, 30, 35, 40, 50, 60]
    K = [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 25, 30, -1, -2, -3]

    with open("../results/partitionCount.set", mode="a+") as file:
        file.write(f" ,")
    for k in K:
        with open("../results/partitionCount.set", mode="a+") as file:
            file.write(f"{k},")
    with open("../results/partitionCount.set", mode="a+") as file:
        file.write("\n")
    for n in N:
        with open("../results/partitionCount.set", mode="a+") as file:
            file.write(f"{n},")
        for k in K:
            k_actual = k
            if k_actual < 0:
                k_actual += n
            elif k_actual == 0.5:
                k_actual = n // 2
            with open("../results/partitionCount.set", mode="a+") as file:
                file.write(f"{partition(n, k_actual)},")
        with open("../results/partitionCount.set", mode="a+") as file:
            file.write("\n")


if __name__ == "__main__":
    thread = threading.Thread(target=main)
    thread.start()