#include <algorithm>
#include <iostream>
#include <vector>

typedef unsigned int uint;

void solve(size_t n, int m, std::vector<uint>& a) {
	std::sort(std::begin(a), std::end(a));

	uint answer = 0; size_t i = n;
	while (m > 0) {
		++answer;
		--i;
		m -= a[i];
	}

	std::cout << answer << "\n";
}

int main() {
	size_t n; int m;
	std::cin >> n >> m;

	std::vector<uint> a(n);
	for (size_t i = 0; i < n; ++i) std::cin >> a[i];

	solve(n, m, a);

	return 0;
}