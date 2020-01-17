#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, r;
    cin >> n >> m >> a >> r;

    cout << m << "\n";

    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);

        int k = 1;
        cout << 1 << " " << k << " " << u + 1 << " " << v + 1 << "\n";
    }

    return 0;
}
