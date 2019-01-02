#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

typedef std::vector<int> vint;
typedef std::vector<vint> vvint;
typedef std::vector<char> vchar;
typedef std::vector<vchar> vvchar;

vint dx = { -1, 0, 1, 0 };
vint dy = { 0, -1, 0, 1 };

void dfs(int x, int y, vint& sz, vvint& num, int& tt, vvchar& a, size_t n, size_t m) {
	++sz[tt];
	num[x][y] = tt;

	for (int i = 0; i < 4; ++i) {
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (std::min(xx, yy) < 0 || xx >= n || yy >= m) 
			continue;

		if (num[xx][yy] != -1 || a[xx][yy] != '.') 
			continue;

		dfs(xx, yy, sz, num, tt, a, n, m);
	}
}

void solve(size_t n, size_t m, vvchar& a) {
	vvchar ans(n, vchar(m));
	vint sz(n * m);
	int tt = 0;
	vvint num(n, vint(m));

	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < m; ++j) 
			num[i][j] = -1;

	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j) {
			if (num[i][j] == -1 && a[i][j] == '.') {
				sz[tt] = 0;
				dfs(i, j, sz, num, tt, a, n, m);
				++tt;
			}
		}
	}

	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j) {
			if (a[i][j] == '.') {
				ans[i][j] = '.';
				continue;
			}

			int cur[4] = { -1, -1, -1, -1 };
			
			for (int k = 0; k < 4; ++k) {
				int x = i + dx[k];
				int y = j + dy[k];
				
				if (std::min(x, y) < 0 || x >= n || y >= m) 
					continue;
				
				if (a[x][y] != '.') 
					continue;
				
				cur[k] = num[x][y];
			}

			std::sort(std::begin(cur), std::end(cur));
			
			int szcur = int(std::unique(std::begin(cur), std::end(cur)) - cur);
			int _ans = 1;
			
			for (int k = 0; k < szcur; ++k)
				if (cur[k] != -1)
					_ans += sz[cur[k]];
			
			_ans %= 10;
			
			ans[i][j] = char('0' + _ans);
		}
	}

	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j)
			std::cout << ans[i][j];
		
		std::cout << "\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m;
	std::cin >> n >> m;

	vvchar a(n, vchar(m));

	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < m; ++j)
			std::cin >> a[i][j];

	solve(n, m, a);
	
    return 0;
}