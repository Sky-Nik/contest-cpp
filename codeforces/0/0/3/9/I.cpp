#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
    }

    vector<int> d(n, -1);
    d[0] = 0;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
    
        for (auto v: g[u]) {
            if (d[v] == -1) {
                q.push(v);
                d[v] = d[u] + 1; 
            }
        }
    }

    int t = 0;
    for (int u = 0; u < n; ++u)
        if (d[u] != -1)
            for (auto v: g[u])
                t = gcd(t, abs(d[u] + 1 - d[v]));

    cout << t << "\n";

    vector<int> cameras;
    for (int u = 0; u < n; ++u)
        if (d[u] != -1 && d[u] % t == 0)
            cameras.push_back(u);

    cout << cameras.size() << "\n";
    for (auto camera: cameras)
        cout << camera + 1 << " ";

    return 0;
}
