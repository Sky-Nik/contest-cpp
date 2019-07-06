#include <algorithm>
#include <iostream>
#include <vector>

typedef unsigned int uint;
typedef std::vector<int> vint;

void solve(size_t n, vint& b) {
	uint answer = n + 1; // inf

	int diff = b[1] - b[0];

	for (int d = diff - 2; d <= diff + 2; ++d) {
		for (int start = b[0] - 1; start <= b[0] + 1; ++start) {
			int pos = start; uint to_change = 0;
			for (size_t i = 0; i < n; ++i) {
				if (abs(pos - b[i]) > 1) {
					to_change = n + 1; // inf
					break;
				} 

				if (pos != b[i])
					++to_change;
				
				pos += d;
			}

			answer = std::min(answer, to_change);
		}
	}

	if (answer == n + 1)
		std::cout << "-1\n";
	else
		std::cout << answer << "\n";
}

int main() {
	size_t n;
	std::cin >> n;

	vint b(n);
	for (size_t i = 0; i < n; ++i)
		std::cin >> b[i];

	solve(n, b);

	return 0;
}