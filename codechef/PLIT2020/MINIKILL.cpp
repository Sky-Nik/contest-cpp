#include <bits/stdc++.h>
using namespace std;

int dfs(const vector<vector<int>>& g, vector<bool>& used, int v) {
    used[v] = true;
    int av = 0, k0 = 0;

    for (auto u: g[v]) {
        if (!used[u]) {
            int au = dfs(g, used, u);

            if (au)
                av += au;
            else
                ++k0;
        }
    }

    if (!av && !k0)
        return 0;  // Leaf

    if (av)
        return av + k0;  // killed by

    return k0 - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> used(n, false);

    cout << max(1, dfs(g, used, 0));

    return 0;
}