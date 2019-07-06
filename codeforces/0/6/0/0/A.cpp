#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <cctype>

bool is_integer(std::string& s) {
	for (size_t i = 0; i < std::size(s); ++i) if (!isdigit(s[i])) return false;
	// leading zeros check, check for "0" and for ""
	return !s.empty() && (s[0] != '0' || s == "0");
}

void solve(std::string& s) {
	s += ';';

	std::string a = "", b = "";

	size_t from = 0;
	for (size_t to = 0; to < std::size(s); ++to) {
		while (s[to] != ';' && s[to] != ',') ++to; // continue?

		std::string word = s.substr(from, to - from);

		if (is_integer(word)) a += word + ',';
		else b += word + ',';

		from = to + 1;
	}

	if (!a.empty()) {
		a.pop_back(); // remove extra , from the end
		std::cout << '"' << a << '"';
	} else std::cout << "-";
	std::cout << "\n";
	
	if (!b.empty()) {
		b.pop_back(); // remove extra , from the end
		std::cout << '"' << b << '"' << "\n";
	} else std::cout << "-";
}

int main() {
	std::string s;
	std::cin >> s;

	solve(s);

	return 0;
}