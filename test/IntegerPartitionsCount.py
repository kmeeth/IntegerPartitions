import sys
import threading
from functools import cache

threading.stack_size(4096 * 10000)
sys.setrecursionlimit(2**31-1)


@cache
def partition(n, k):
    if k == n or k == 1:
        return 1
    if n <= 0 or k <= 0:
        return 0
    return partition(n - k, k) + partition(n, k - 1)


def main():
    N = [100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 2000, 3000, 4000]
    K = [3, 4, 5, 6, 7, 8, 9, 10, 0.5]
    for k in K:
        row = []
        for n in N:
            k_actual = k
            if k_actual < 0:
                k_actual += n
            elif k_actual == 0.5:
                k_actual = n // 2
            row.append(partition(n, k_actual))
        print(row)


if __name__ == "__main__":
    thread = threading.Thread(target=main)
    thread.start()