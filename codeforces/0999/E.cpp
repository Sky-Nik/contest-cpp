#include <bits/stdc++.h>

using namespace std;

void dfs(int f, vector<vector<int>>& g, vector<bool>& u) {
	u[f] = true;

	for (int t: g[f])
		if (!u[t])
			dfs(t, g, u);
}

int dfs_count(int f, vector<vector<int>>& g, vector<bool>& u) {
	int a = 1; u[f] = true;

	for (int t: g[f])
		if (!u[t])
			a += dfs_count(t, g, u);

	return a;
}

void solve(int n, int m, int s, vector<vector<int>>& g) {
	vector<bool> u(n, false);

	dfs(s - 1, g, u);

	vector<pair<int, int>> cnt;

	for (int i = 0; i < n; ++i) {
		if (!u[i]) {
			vector<bool> u2(n, false);
			cnt.push_back(make_pair(dfs_count(i, g, u2), i));
		}
	}

	sort(begin(cnt), end(cnt));

	// TODO
}

int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	int n, m, s; cin >> n >> m >> s;

	vector<vector<int>> g(n);
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		g[u - 1].push_back(v - 1);
	}

	solve(n, m, s, g);

	return 0;
}