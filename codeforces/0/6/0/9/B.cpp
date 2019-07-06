#include <iostream>
#include <vector>

typedef unsigned int uint;

typedef unsigned long long ullong;

inline ullong cn2(ullong n) {
	return ((n + 1) * n) >> 1;
}

void solve(uint n, uint m, std::vector<uint>& a) {
	std::vector<uint> frequencies(m);
	for (size_t i = 0; i < n; ++i) ++frequencies[a[i] - 1];

	ullong answer = cn2(n);
	
	for (size_t j = 0; j < m; ++j) answer -= cn2(frequencies[j]);

	std::cout << answer << "\n";
}

int main() {
	uint n, m;
	std::cin >> n >> m;

	std::vector<uint> a(n);
	for (size_t i = 0; i < n; ++i) std::cin >> a[i];

	solve(n, m, a);

	return 0;
}