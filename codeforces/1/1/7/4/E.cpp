#include <bits/stdc++.h>
using namespace std;

int dp[1000005][21][2];

int f(int n, int x, int y) {
    return n / ((1 << x) * (y ? 3 : 1));
}

int main() {
    int n; cin >> n;
    
    int p = 0; while ((1 << p) <= n) ++p; --p;

    int mod = 1000000007;

    dp[1][p][0] = 1; if ((1 << (p - 1)) * 3 <= n) dp[1][p - 1][1] = 1;

    for (int i = 1; i < n; ++i) {
        for (int x = 0; x <= p; ++x) {
            for (int y = 0; y <= 1; ++y) {
                dp[i + 1][x][y] = (dp[i + 1][x][y] + 1LL * dp[i][x][y] * (f(n, x, y) - i)) % mod;                
                if (x) dp[i + 1][x - 1][y] = (dp[i + 1][x - 1][y] + 1LL * dp[i][x][y] * (f(n, x - 1, y) - f(n, x, y))) % mod;
                if (y) dp[i + 1][x][y - 1] = (dp[i + 1][x][y - 1] + 1LL * dp[i][x][y] * (f(n, x, y - 1) - f(n, x, y))) % mod;
            }
        }
    }

    cout << dp[n][0][0];

    return 0;
}