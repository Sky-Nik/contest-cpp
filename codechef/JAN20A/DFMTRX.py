#!/usr/bin/env python


def solve(n):
    a = [[0 for _ in range(n)] for _ in range(n)]
    
    for i in range(n):
        a[i][i] = 2 * n - 1

    for k in range(1, n):
        a[k - 1][n - 1] = k
        a[n - 1][k - 1] = k + n - 1

        i, j = k, k
        
        for _ in range(n // 2 - 1):
            i += 1
            
            if i == n:
                i = 1
            
            j -= 1
            
            if j == 0:
                j = n - 1

            if i < j:
                a[i - 1][j - 1] = k
                a[j - 1][i - 1] = k + n - 1
            else:
                a[j - 1][i - 1] = k
                a[i - 1][j - 1] = k + n - 1

    for i in range(n):
        print(*a[i])


if __name__ == '__main__':
    for _ in range(int(input())):  # t
        n = int(input())

        if n == 1:
            print("Hooray")
            print(1)
        elif n % 2 == 1:
            print("Boo")
        else:
            print("Hooray")
            solve(n)
