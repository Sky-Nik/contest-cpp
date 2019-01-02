#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

typedef unsigned int uint;
typedef std::vector<int> vint;

int main() {
	size_t n;
	std::cin >> n;

	vint x(n);
	for (size_t i = 0; i < n; ++i)
		std::cin >> x[i];
	
	std::sort(std::begin(x), std::end(x));
	vint res = { x[0] };
	
	for (size_t i = 0; i < n; ++i) {
		for (uint j = 0; j < 31; ++j) {
			int lx = x[i] - (1 << j);
			int rx = x[i] + (1 << j);
			
			bool isl = std::binary_search(std::begin(x), std::end(x), lx);
			bool isr = std::binary_search(std::begin(x), std::end(x), rx);
			
			if (isl && isr && std::size(res) < 3)
				res = { lx, x[i], rx };
			
			if (isl && std::size(res) < 2)
				res = { lx, x[i] };

			if (isr && std::size(res) < 2)
				res = { x[i], rx };
		}
	}
	
	std::cout << std::size(res) << "\n";
	for (auto it : res)
		std::cout << it << " ";
	
	return 0;
}