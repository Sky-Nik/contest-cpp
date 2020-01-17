#include <bits/stdc++.h>
using namespace std;

const int64_t mod = 1'000'000'007;

int64_t bin_pow(int64_t n, int64_t p) {
    if (!p)
        return 1;

    if (p & 1)
        return (n * bin_pow(n, p - 1)) % mod;

    return bin_pow((n * n) % mod, p >> 1);
}

int64_t inv(int64_t n) {
    return bin_pow(n, mod - 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64_t n, k;
    cin >> n >> k;

    vector<int64_t> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
        fact[i] = (i * fact[i - 1]) % mod;

    vector<int64_t> invf(n + 1);
    for (int i = 0; i <= n; ++i)
        invf[i] = inv(fact[i]);

    vector<int64_t> a(n);
    for (auto& ai: a)
        cin >> ai;

    map<int64_t, int64_t> mp;
    for (auto ai: a)
        ++mp[ai];

    vector<int64_t> cnt;
    for (auto kv: mp)
        cnt.push_back(kv.second);

    int64_t sz = cnt.size();

    vector<vector<int64_t>> dp(sz + 1, vector<int64_t>(k + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int l = 0; l <= cnt[i]; ++l) {
                if (j + l > k)
                    break;

                dp[i + 1][j + l] = (dp[i + 1][j + l] +
                    (dp[i][j] * ((fact[cnt[i]] * invf[cnt[i] - l]) % mod)) % mod) % mod;
            }
        }
    }

    int64_t p = dp[sz][k], q = (fact[n] * invf[n - k]) % mod;

    cout << (p * inv(q)) % mod;

    return 0;
}
