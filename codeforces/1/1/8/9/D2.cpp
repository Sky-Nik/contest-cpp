#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1000 + 10;
bool banned[MAXN];

int dfs(int start, vector<vector<pair<int, int>>>& g) {
    for (int )

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> u(n), v(n), val(n);
    vector<vector<pair<int, int>>> g(n);
    for (int i = 1; i < n; ++i) {
        cin >> u[i] >> v[i] >> val[i];
        --u[i];
        --v[i];
        g[u[i]].push_back(make_pair(v[i], val[i]));
        g[v[i]].push_back(make_pair(u[i], val[i]));
    }
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 2) {
            cout << "NO";
            return 0;
        }
    }
    fill(begin(banned), end(banned), false);
    cout << "YES\n" << 6 * (n - 1) << "\n";
    for (int i = 1; i < n; ++i) {
        if (g[u[i]].size() != 1) {
            banned[u[i]] = true;
            int w = dfs(v[i], g);
            fill(begin(banned), end(banned), false);
            banned[v[i]] = true;
            int l1 = dfs(u[i], g);
            fill(begin(banned), end(banned), false);
            banned[v[i]] = true;
            banned[l1] = true;
            int l2 = dfs(u[i], g);
            fill(begin(banned), end(banned), false);
        } else {
            banned[u[i]] = true;
            l1 = dfs(v[i], banned, g);
            banned[u[i]] = true;
            banned[l1] = true;
            l2 = dfs(v[i], banned, g);
        }

    }
    return 0;
}