#include <algorithm>
#include <iostream>
#include <vector>

typedef unsigned int uint;
typedef std::vector<int> vint;
typedef std::vector<uint> vuint;

void solve(size_t n, uint k, vuint& a) {
	vint cnt(101, -1);

	for (size_t i = 0; i < n; ++i)
		cnt[a[i]] = i;

	if (std::count_if(std::begin(cnt), std::end(cnt), [](int i) { return i != -1; }) < k) {
		std::cout << "NO";
		return;
	}

	std::cout << "YES\n";
	for (size_t i = 0; i < 101; ++i) {
		if (k > 0 && cnt[i] != -1) {
			std::cout << cnt[i] + 1 << " ";
			--k;
		}
	}
}

int main() {
	size_t n; uint k;
	std::cin >> n >> k;

	vuint a(n);
	for (size_t i = 0; i < n; ++i)
		std::cin >> a[i];

	solve(n, k, a);

	return 0;
}