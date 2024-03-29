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
    K = [3, 4, 5, 6, 7, 8, 9, 10, -2, -3, -4, 0.5]

    for k in K:
        for n in N:
            with open("out.txt", mode="a") as file:
                k_actual = k
                if k_actual < 0:
                    k_actual += n
                elif k_actual == 0.5:
                    k_actual = n // 2
                file.write(f"{partition(n, k_actual)} ")
        with open("out.txt", mode="a") as file:
            file.write("\n")


if __name__ == "__main__":
    thread = threading.Thread(target=main)
    thread.start()