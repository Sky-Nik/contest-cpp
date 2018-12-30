#include <iostream>

typedef long long llong;
typedef unsigned int uint;

uint log2(uint n) {
	uint answer = 0;
	
	while (n > 1) {
		n >>= 1;
		++answer;
	}

	return answer;
}

void solve(uint n){
	llong answer = 0;
	
	// 1 + 2 + ... + n = (n + 1) * n / 2
	answer += (n + 1LL) * n / 2;
	
	// k = max m : 2^m <= n
	uint k = log2(n);

	// - 2 * (2^0 + 2^1 + 2^2 + ... + 2^k) = - 2 * (2^(k + 1) - 1)
	answer -= ((1 << (k + 1LL)) - 1) << 1;

	std::cout << answer << "\n";
}

int main() {
	uint t;
	std::cin >> t;
	
	uint n;
	for (uint i = 0; i < t; ++i) {
		std::cin >> n;
		solve(n);
	}

	return 0;
}
