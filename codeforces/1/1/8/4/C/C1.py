#!/usr/bin/env python
import sys

n = int(input())
k = (n << 2) + 1

x, y = [], []
for i in range(k):
    xi, yi = map(int, input().split())
    x.append(xi)
    y.append(yi)

for lx in range(0, 50):
    for ly in range(0, 50):
        for side_len in range(1, 51):
            ok, idx = True, -1
            for i in range(k):
                if not (((x[i] == lx or x[i] == lx + side_len) and ly <= y[i] <= ly + side_len) or
                    ((lx <= x[i] <= lx + side_len) and (y[i] == ly or y[i] == ly + side_len))):
                    if idx != -1:
                        ok = False
                    else:
                        idx = i
            if ok:
                print(x[idx], y[idx])
                sys.exit(0)
