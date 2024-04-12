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

    for n in N:
        mx, best = 0, 1
        for k in range(1, n + 1):
            p = partition(n, k)
            mx = max(mx, p)
            if mx == p:
                best = k
        with open("../output/maxPartitionCount.set", mode="a") as file:
            file.write(f"{n} : {best} - {mx}\n")
    with open("../output/partitionCount.set", mode="a") as file:
        file.write("\n")


if __name__ == "__main__":
    thread = threading.Thread(target=main)
    thread.start()