#include <algorithm>
#include <iostream>
#include <string>

typedef unsigned int uint;

void solve(std::string& s, size_t li, size_t ri, uint ki) {
	ki %= (ri - li + 1);

	std::rotate(std::begin(s) + li - 1, std::begin(s) + ri - ki, std::begin(s) + ri);
}

int main() {
	std::string s;
	std::cin >> s;

	uint m;
	std::cin >> m;

	size_t li, ri; int ki;
	for(uint i = 0; i < m; ++i) {
		std::cin >> li >> ri >> ki;
		solve(s, li, ri, ki);
	}

	std::cout << s;

	return 0;
}
