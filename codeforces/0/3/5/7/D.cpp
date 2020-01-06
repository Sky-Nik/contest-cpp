#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n, m;
    string x, y;
    cin >> n >> m >> x >> y;

    int64_t xl = x.length(), yl = y.length(); 

    int64_t g = gcd(xl, yl), l = lcm(xl, yl);

    int64_t ans = l;

    vector<vector<int>> cnt(26, vector<int>(g, 0));
    for (int j = 0; j < yl; ++j) ++cnt[y[j] - 'a'][j % g];

    for (int i = 0; i < xl; ++i) ans -= cnt[x[i] - 'a'][i % g];

    cout << ans * (n * xl / l);

    return 0;
}
