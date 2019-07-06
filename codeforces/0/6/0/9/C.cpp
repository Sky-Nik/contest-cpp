#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>

typedef unsigned int uint;

typedef long long llong;

void solve(size_t n, std::vector<uint>& m) {
	uint s = std::accumulate(std::begin(m), std::end(m), 0u);

	if (s % n == 0) {
		uint balancedLoad = s / n;

		uint answer = 0;
		for (size_t i = 0; i < n; ++ i) answer += abs(m[i] - balancedLoad);
		answer >>= 1;

		std::cout << answer << "\n";		
	} else {
		uint balancedHighLoad = ceil((1. * s) / n), balancedLowLoad = s / n,
			numHighLoad = s % n, numLowLoad = n - s % n;

		std::sort(std::begin(m), std::end(m));

		uint answer = 0;
		for (size_t i = n; i-- > numLowLoad;) answer += abs(m[i] - balancedHighLoad);
		for (size_t i = numLowLoad; i-- > 0;) answer += abs(balancedLowLoad - m[i]);
		answer >>= 1;

		std::cout << answer << "\n";
	}
}

int main() {
	size_t n;
	std::cin >> n;

	std::vector<uint> m(n);
	for (size_t i = 0; i < n; ++i) std::cin >> m[i];

	solve(n, m);

	return 0;
}