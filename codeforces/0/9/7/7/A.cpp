#include <iostream>

typedef unsigned int uint;

void solve(int n, uint k) {
	for (uint i = 0; i < k; ++i) {
		if (n % 10 != 0) --n;
		else n /= 10;
	}
	std::cout << n << "\n";
}

int main() {
	int n; uint k;
	std::cin >> n >> k;

	solve(n, k);

	return 0;
}