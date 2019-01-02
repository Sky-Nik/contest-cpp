#include <iostream>
#include <iterator>
#include <string>

void solve(std::string& a, std::string& b) {
	size_t i = 0, j = 0, la = std::size(a), lb = std::size(b);
	while (i < la && a[i] == '0')
		++i; 
	while (j < lb && b[j] == '0')
		++j;

	if (la - i > lb - j) {
		std::cout << ">";
		return;
	}
	if (la - i < lb - j) {
		std::cout << "<";
		return;
	}

	for (size_t k = 0; k + i < la; ++k) {
		if (a[i + k] < b[j + k]) {
			std::cout << "<";
			return;
		}
		if (a[i + k] > b[j + k]) {
			std::cout << ">";
			return;
		}
	}

	std::cout << "=";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string a, b;
	std::cin >> a >> b;

	solve(a, b);

	return 0;
}