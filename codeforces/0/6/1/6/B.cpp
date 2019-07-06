#include <algorithm>
#include <iostream>
#include <vector>

typedef std::vector<int> vint;
typedef std::vector<vint> vvint;

void solve(size_t n, size_t m, vvint& c) {
	vint row_min(n);
	for (size_t i = 0; i < n; ++i) {
		row_min[i] = c[i][0];
		for (size_t j = 1; j < m; ++j)
			row_min[i] = std::min(row_min[i], c[i][j]);
	}

	int col_max = row_min[0];
	for (size_t i = 1; i < n; ++i)
		col_max = std::max(col_max, row_min[i]);

	std::cout << col_max;
}

int main() {
	size_t n, m;
	std::cin >> n >> m;

	vvint c(n, vint(m));
	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < m; ++j)
			std::cin >> c[i][j];

	solve(n, m, c);

	return 0;
}