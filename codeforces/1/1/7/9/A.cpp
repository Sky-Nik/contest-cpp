#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    deque<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    vector<pair<int, int>> ans((n << 1));
    for (int i = 0, a, b; i < (n << 1); ++i) {
        a = d.front();
        d.pop_front();
        b = d.front();
        d.pop_front();
        ans[i] = make_pair(a, b);
        if (a > b) {
            d.push_front(a);
            d.push_back(b);
        } else {
            d.push_front(b);
            d.push_back(a);
        }
    }
    ll m;
    for (int i = 0, idx; i < q; ++i) {
        cin >> m;
        idx = (m < n) ? (m - 1) : (((m - 1) % (n - 1) + (n - 1)));
        cout << ans[idx].first << " " << ans[idx].second << "\n";
    }

    return 0;
}