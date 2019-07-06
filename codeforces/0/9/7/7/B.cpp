#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

typedef std::vector<int> vint;
typedef std::vector<vint> vvint;

void solve(size_t n, std::string s) {
	vvint A(26, vint(26, 0));

	for (size_t i = 0; i  + 1 < n; ++i) 
		++A[s[i] - 'A'][s[i + 1] - 'A'];
	
	int M = 0;
	for (int i = 0; i < 26; ++i) 
		for (int j = 0; j < 26; ++j) 
			M = std::max(M, A[i][j]);

	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			if (M == A[i][j]) {
				std::cout << char(i + 'A') << char(j + 'A') << "\n";
				return;
			}
		}
	}
}

int main() {
	size_t n;
	std::string s;
	std::cin >> n >> s;

	solve(n, s);

	return 0;
}