#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

typedef unsigned long long uint;
typedef std::pair<int, int> pint;
typedef std::vector<int> vint;
typedef std::vector<pint> vpint;

void solve(size_t n, vint& f) {
	vpint index_f(n);
	for (size_t i = 0; i < n; ++i) 
		index_f[i] = pint(f[i], i);

	std::sort(std::begin(index_f), std::end(index_f));

	uint answer = 0;
	for (size_t i = 0; i + 1 < n; ++i)
		answer += abs(index_f[i].second - index_f[i + 1].second);

	std::cout << answer << "\n";
}

int main() {
	size_t n;
	std::cin >> n;

	vint f(n);
	for (size_t i = 0; i < n; ++i) 
		std::cin >> f[i];

	solve(n, f);

	return 0;
}