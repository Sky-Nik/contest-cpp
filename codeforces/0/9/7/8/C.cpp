#include <iostream>
#include <vector>

typedef unsigned long long uint;
typedef std::vector<uint> vuint;

void solve(size_t n, vuint& a, size_t m, vuint& b) {
	vuint prefix_sums(n + 1);
	prefix_sums[0] = 0;
	for (size_t i = 0; i < n; ++i)
		prefix_sums[i + 1] = prefix_sums[i] + a[i];

	size_t f = 0;
	for (auto bi: b) {
		while (bi > prefix_sums[f])
			++f;
		std::cout << f << " " << bi - prefix_sums[f - 1] << "\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	size_t n, m;
	std::cin >> n >> m;

	vuint a(n);
	for (size_t i = 0; i < n; ++i)
		std::cin >> a[i];

	vuint b(m);
	for (size_t j = 0; j < m; ++j)
		std::cin >> b[j];

	solve(n, a, m, b);

	return 0;
}