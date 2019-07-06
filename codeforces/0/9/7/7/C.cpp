#include <algorithm>
#include <iostream>
#include <vector>

typedef unsigned int uint;
typedef std::vector<int> vint;

void solve(size_t n, uint k, vint& A) {
	std::sort(std::begin(A), std::end(A));
	
	if (k == 0 && A[0] == 1) std::cout << "-1\n";
	else if (k == 0 && A[0] > 1) std::cout << "1\n";
	else if (n == k) std::cout << "1000000000\n";
	else if (A[k] > A[k - 1]) std::cout << A[k - 1] << "\n";
	else std::cout << "-1\n";
}

int main() {
	size_t n; uint k;
	std::cin >> n >> k;

	vint A(n);
	for (size_t i = 0; i < n; ++i) std::cin >> A[i];
	
	solve(n, k, A);

	return 0;
}