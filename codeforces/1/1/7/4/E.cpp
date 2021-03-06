#include <bits/stdc++.h>
using namespace std;

const int mod = 1'000'000'007;

int dp[1'000'005][21][2];

inline int64_t f(int64_t n, int64_t x, int64_t y) {
    return n / ((1 << x) * (y ? 3 : 1));
}

inline int mul(int64_t x, int64_t y, int m = mod) {
    return (x * y) % mod;
}

inline void iadd(int& x, int y, int m = mod) {
    x += y;

    if (x >= m)
        x -= m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int p = 0;

    while ((1 << p) <= n)
        ++p;

    --p;

    dp[1][p][0] = 1;

    if ((1 << (p - 1)) * 3 <= n)
        dp[1][p - 1][1] = 1;

    for (int i = 1; i < n; ++i) {
        for (int x = 0; x <= p; ++x) {
            for (int y = 0; y <= 1; ++y) {
                iadd(dp[i + 1][x][y], mul(dp[i][x][y], f(n, x, y) - i));

                if (x)
                    iadd(dp[i + 1][x - 1][y], mul(dp[i][x][y], f(n, x - 1, y) - f(n, x, y)));

                if (y)
                    iadd(dp[i + 1][x][y - 1], mul(dp[i][x][y], f(n, x, y - 1) - f(n, x, y)));
            }
        }
    }

    cout << dp[n][0][0];

    return 0;
}