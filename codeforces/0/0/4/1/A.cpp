#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s, t;
    std::cin >> s >> t;

    std::reverse(s.begin(), s.end());

    if (s == t) {
        std::cout << "YES";
    } else {
        std::cout <<"NO";
    }

    return 0;
}