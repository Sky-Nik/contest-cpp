#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

typedef std::vector<std::string> vstring;

void solve(size_t n, vstring& vs) {
	std::sort(std::begin(vs), std::end(vs), 
		[](std::string s1, std::string s2) { return std::size(s1) < std::size(s2); });

	for (size_t i = 0; i + 1 < n; ++i) {
		if (vs[i + 1].find(vs[i]) == std::string::npos) {
			std::cout << "NO";
			return;
		}
	}

	std::cout << "YES\n";
	for (size_t i = 0; i < n; ++i) 
		std::cout << vs[i] << "\n";
}

int main() {
	size_t n;
	std::cin >> n;

	vstring vs(n);
	for (size_t i = 0; i < n; ++i)
		std::cin >> vs[i];

	solve(n, vs);

	return 0;
}