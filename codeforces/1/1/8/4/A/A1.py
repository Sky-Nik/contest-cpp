#!/usr/bin/env python
r = int(input())

for x in range(1, 10**6):
    if (r - (x**2 + x + 1)) % (x << 1) == 0:
        y = (r - (x**2 + x + 1)) // (x << 1)
        if y > 0:
            print(x, y)
            break
else:
    print("NO")
