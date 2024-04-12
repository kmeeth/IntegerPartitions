import sys
import threading
from functools import cache

threading.stack_size(4096 * 10000)
sys.setrecursionlimit(2**31-1)


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
    N = [100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 2000, 3000, 4000, 5000, 10000, 20000, 30000, 40000]

    for n in N:
        mx, best = 0, 1
        for k in range(1, n + 1):
            p = partition(n, k)
            mx = max(mx, p)
            if mx == p:
                best = k
        with open("../output/maxPartitionCount.int", mode="a") as file:
            file.write(f"{n} : {best} - {mx}\n")
    with open("../output/maxPartitionCount.int", mode="a") as file:
        file.write("\n")


if __name__ == "__main__":
    thread = threading.Thread(target=main)
    thread.start()