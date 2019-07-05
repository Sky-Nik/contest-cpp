#include <bits/stdc++.h>

using namespace std;

typedef long long llong;

void solve(int n, int m, vector<vector<int>>& g) {
	vector<int> used(n, false);
	used[0] = true;

	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(0);

	while (!pq.empty()) {
		int cur = pq.top(); pq.pop();
		cout << cur + 1 << " ";

		for (int to: g[cur]) {
			if (!used[to]) {
				pq.push(to);
				used[to] = true;
			}
		}
	}

	cout << "\n";
}

int main() {
	int n, m; cin >> n >> m;

	vector<vector<int>> g(n);
	for (int i = 0, ui, vi; i < m; ++i) {
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].push_back(vi);
		g[vi].push_back(ui);
	}

	solve(n, m, g);

	return 0;
}