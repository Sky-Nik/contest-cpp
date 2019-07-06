#include <iostream>
#include <string>
#include <vector>

typedef std::vector<char> vchar;

void solve(std::string& s) {
	vchar stack;

	int answer = 0;

	for (auto c: s) {
		if (c == '(' || c == '<' || c == '{' || c == '[')
			stack.push_back(c);
		else {
			if (stack.empty()) {
				std::cout << "Impossible\n";
				return;
			}

			char b = stack.back();
			if (b == '(' && c != ')' || b == '[' && c != ']' || 
				b == '{' && c != '}' || b == '<' && c != '>') 
				++answer;

			stack.pop_back();
		}
	}

	if (!stack.empty())
		std::cout << "Impossible\n";
	else
		std::cout << answer << "\n";
}

int main() {
	std::string s;
	std::cin >> s;

	solve(s);

	return 0;
}