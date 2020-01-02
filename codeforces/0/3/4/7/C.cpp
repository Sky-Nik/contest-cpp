#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

namespace nt {
    template<typename T>
    T gcd2(T x, T y) {
        while (x != 0) {
            std::tie(x, y) = std::make_tuple(y % x, x);
        }
        return y;
    }

    template<typename T>
    T gcd(const std::vector<T>& a) {
        T acc = 0;
        for (const auto& ai : a) {
            acc = gcd2(acc, ai);
        }
        return acc;
    }
} // nt

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& ai : a) { 
        std::cin >> ai;
    }

    int max = *std::max_element(a.begin(), a.end());
    int gcd = nt::gcd(a);

    if ((max / gcd - n) % 2) {
        std::cout << "Alice";
    } else {
        std::cout << "Bob";
    }

    return 0;
}
