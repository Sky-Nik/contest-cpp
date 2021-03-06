#include <algorithm>
#include <iostream>
#include <vector>

typedef unsigned int uint;
typedef long long llong;
typedef std::vector<llong> vllong;

uint exp_3(llong a) {
	uint ans = 0;
	
	while (a % 3 == 0) {
		a /= 3;
		++ans;
	}

	return ans;
}

uint exp_2(llong a) {
	int ans = 0;

	while (a % 2 == 0) {
		a /= 2;
		++ans;
	}

	return ans;
}

bool comp(llong a, llong b) {
	if (exp_3(a) > exp_3(b))
		return true;
	else if (exp_3(a) < exp_3(b))
		return false;
	else if (exp_2(a) < exp_2(b))
		return true;
	else 
		return false;
}

void solve(size_t n, vllong& A) {
	std::sort(std::begin(A), std::end(A), comp);
	
	for (size_t i = 0; i < n; ++i) std::cout << A[i] << " ";
	std::cout << "\n";
}

int main() {
	size_t n;
	std::cin >> n;
	
	vllong A(n);
	for (size_t i = 0; i < n; ++i) std::cin >> A[i];

	solve(n, A);

	return 0;
}