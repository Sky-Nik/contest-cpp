#include <algorithm>
#include <iostream>
#include <vector>

typedef unsigned int uint;
typedef std::vector<int> vint;

void solve(size_t n, uint w, vint& a) {
	int low = 0, now = 0, high = 0;
	for (auto ai: a) {
		now += ai;
		low = std::min(low, now);
		high = std::max(high, now);
	}

	if (high - low <= w)
		std::cout << w + 1 + low - high << "\n";
	else
		std::cout << "0\n";
}

int main() {
	size_t n; uint w;
	std::cin >> n >> w;

	vint a(n);
	for (size_t i = 0; i < n; ++i)
		std::cin >> a[i];

	solve(n, w, a);

	return 0;
}