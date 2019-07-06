#include <iostream>
#include <iterator>
#include <string>
#include <vector>

typedef unsigned int uint;

const uint num_letters = 26;

void solve(std::string& s) {
	std::vector<uint> frequencies(num_letters, 0);
	
	for (size_t i = 0; i < std::size(s); ++i) 
		++frequencies[static_cast<int>(s[i]) - static_cast<int>('a')];

	size_t to = 0, from = num_letters - 1;
	while (to < from) {
		if (frequencies[to] % 2 == 0) ++to;
		else if (frequencies[from] % 2 == 0) --from;
		else {
			++frequencies[to];
			--frequencies[from];
			++to;
			--from;
		}
	}

	for (size_t i = 0; i < num_letters; ++i)
		for (uint j = 0; j < (frequencies[i] >> 1); ++j)
			std::cout << static_cast<char>(static_cast<int>('a') + i);

	for (size_t i = 0; i < num_letters; ++i)
		if (frequencies[i] & 1)
			std::cout << static_cast<char>(static_cast<int>('a') + i);

	for (size_t i = num_letters; i-- > 0;)
		for (uint j = 0; j < (frequencies[i] >> 1); ++j)
			std::cout << static_cast<char>(static_cast<int>('a') + i);
}

int main() {
	std::string s;
	std::cin >> s;

	solve(s);

	return 0;
}