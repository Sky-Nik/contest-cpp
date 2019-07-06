#include <algorithm>
#include <iostream>
#include <vector>

typedef std::vector<int> vint;

const int MAXN = 200010;
size_t n;
int ans = 0;
vint g[MAXN];
bool used[MAXN];
vint comp;

void dfs (int v) {
	used[v] = true;
	comp.push_back(v);
	for (size_t i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to])
			dfs(to);
	}
}

void find_comps() {
	for (size_t i = 0; i < n; ++i)
		used[i] = false;

	for (size_t i = 0; i < n; ++i)
		if (!used[i]) {
			comp.clear();
			dfs(i);
			++ans;
			for (size_t j = 0; j < comp.size(); ++j) {
				if (g[comp[j]].size() != 2) {
					--ans;
					break;
				}
			}
		}
}

int main() {
	size_t m;
	int a, b;
	std::cin >> n >> m;
	for (size_t i = 0; i < m; ++i) {
		std::cin >> a >> b;
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	find_comps();

	std::cout << ans << '\n';

	return 0;
}