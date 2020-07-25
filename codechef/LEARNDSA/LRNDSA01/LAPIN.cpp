#include <iostream>
#include <string>
#include <unordered_map>

auto cnt(const std::string& s) {
    std::unordered_map<char, int> cnt_;
    for (auto ch : s) {
        ++cnt_[ch];
    }
    return cnt_;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        int half_length = s.length() >> 1;
        if (cnt(s.substr(0, half_length)) ==
            cnt(s.substr(half_length + (s.length() & 1), half_length))) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
