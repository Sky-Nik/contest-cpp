#include <bits/stdc++.h>
using namespace std;

const int kMod = 1'000'000'007;

bool is_good(const string& s, int l, int r, const vector<int>& a) {
    for (int i = l; i < r; ++i)
        if (a[s[i] - 'a'] < r - l)
            return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> a(26);
    for (auto& ai: a)
        cin >> ai;

    vector<int> dp_cnt(n + 1, 0);
    dp_cnt[0] = 1;
    
    vector<int> dp_min(n + 1);
    for (int i = 0; i <= n; ++i)
        dp_min[i] = i;

    vector<int> dp_max(n + 1, 1);
    dp_max[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (is_good(s, j, i, a)) {
                dp_cnt[i] = (dp_cnt[i] + dp_cnt[j]) % kMod;
                dp_max[i] = max(dp_max[i], i - j);
                dp_min[i] = min(dp_min[i], dp_min[j] + 1);
            }
        }
    }

    cout << dp_cnt[n] << "\n" << *max_element(dp_max.begin(), dp_max.end()) << "\n" << dp_min[n];

    return 0;
}
