#!/usr/bin/env python
def solve(n, k):
    r = -1
    sk = ((k + 1) * k) // 2
    d = 1
    while d**2 <= n:
        if n % d == 0:
            g1 = d
            if sk * g1 <= n:
                r = max(r, g1)

            g2 = n // d
            if sk * g2 <= n:
                r = max(r, g2)
        d += 1

    return r


if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        n, k = map(int, input().split())
        print(solve(n, k))
