#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <set>

typedef std::set<int> sint;
typedef std::vector<int> vint;

void solve(size_t n, vint& a) {
	std::map<int, size_t> last_occurence_index;

	for (size_t i = 0; i < n; ++i)
		last_occurence_index[a[i]] = i;

	std::cout << std::size(last_occurence_index) << "\n";

	sint s;
	for (auto [k, v]: last_occurence_index)
		s.insert(v);

	for (size_t i = 0; i < n; ++i)
		if (s.find(i) != s.end())
			std::cout << a[i] << " ";
}

int main() {
	size_t n;
	std::cin >> n;

	vint a(n);
	for (size_t i = 0; i < n; ++i) 
		std::cin >> a[i];

	solve(n, a);

	return 0;
}