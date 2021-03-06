#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
inline istream& operator >> (istream& is, vector<T>& v) {
    for (auto& e: v) {
        cin >> e;
    }
    return is;
}

const int MAXN = 300000 + 1000;
ll dp[MAXN][3][3];

int main() {
    ll n, x;
    cin >> n >> x;
    vector<int> a(n);
    cin >> a;
    
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                dp[i][j][k] = numeric_limits<ll>::min();
            }
        }
    }
    dp[0][0][0] = 0;
    
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (k < 2) {
                    dp[i][j][k + 1] = max(dp[i][j][k + 1], dp[i][j][k]);
                }
                if (j < 2) {
                    dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
                }
                if (i < n) {
                    dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + (j == 1 ? a[i] : 0) * ll(k == 1 ? x : 1));
                }
            }
        }
    }
    
    cout << dp[n][2][2];
}