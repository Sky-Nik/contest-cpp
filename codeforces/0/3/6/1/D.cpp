#include <bits/stdc++.h>
using namespace std;

bool possible(const vector<int64_t>& a, int64_t n, int64_t k, int64_t c) {
    vector<int64_t> dp(n + 1);
    for (int64_t i = 0; i <= n; ++i)
        dp[i] = i;

    for (int64_t i = 1; i < n; ++i)
        for (int64_t j = 0; j < i; ++j)
            if (abs(a[i] - a[j]) <= (i - j) * c)
                dp[i] = min(dp[i], dp[j] + (i - 1 - j));

    for (int64_t j = 0; j < n; ++j)
        dp[n] = min(dp[n], dp[j] + (n - 1 - j));

    return dp[n] <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n, k;
    cin >> n >> k;

    vector<int64_t> a(n);
    for (auto& ai: a)
        cin >> ai;

    int64_t lower = -1, middle, upper = 2'000'000'000LL;

    while (lower + 1 != upper) {
        middle = (lower + upper) >> 1;
        if (possible(a, n, k, middle))
            upper = middle;
        else
            lower = middle;
    }

    cout << upper;

    return 0;
}
