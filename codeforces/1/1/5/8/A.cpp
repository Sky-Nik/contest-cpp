#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> b(n), g(m);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    sort(begin(b), end(b));
    for (int i = 0; i < m; ++i) {
        cin >> g[i];
    }
    sort(begin(g), end(g));
    if ((g[0] < b[n - 1]) || ((n == 1) && (g[0] > b[0]))) {
        cout << -1;
    } else {
        ll ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            ans += (ll)(b[i]) * m;
        }
        ans += accumulate(begin(g), end(g), 0ll);
        if (g[0] > b[n - 1]) {
            ans += (b[n - 1] - b[n - 2]);
        }
        cout << ans;
    }
    return 0;
}