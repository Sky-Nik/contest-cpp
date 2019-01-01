#include <iostream>
#include <string>

typedef unsigned int uint;

void solve(size_t n, size_t p, size_t q, std::string s) {
	for (uint a = 0; a * p <= n; ++a) {
		if ((n - a * p) % q == 0) {
			uint b = (n - a * p) / q;

			std::cout << a + b << "\n";

			uint pos = 0;
			for (; pos < a * p; pos += p)
				std::cout << s.substr(pos, p) << "\n";

			for (; pos < n; pos += q)
				std::cout << s.substr(pos, q) << "\n";

			return;
		}
	}

	std::cout << "-1\n";
}

int main() {
	size_t n, p, q;
	std::cin >> n >> p >> q;

	std::string s;
	std::cin >> s;

	solve(n, p, q, s);

	return 0;
}