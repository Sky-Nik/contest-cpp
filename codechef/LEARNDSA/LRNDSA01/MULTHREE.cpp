#include <iostream>
#include <tuple>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t, d0, d1;
    int64_t k;
    std::cin >> t;
    while (t--) {
        std::cin >> k >> d0 >> d1;
        k -= 2;
        k %= 2520;
        int s = d0 + d1;
        while (k--) {
            std::tie(d0, d1) = std::make_tuple(d1, s % 10);
            s += d1;
        }
        if (s % 3) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }

    return 0;
}
