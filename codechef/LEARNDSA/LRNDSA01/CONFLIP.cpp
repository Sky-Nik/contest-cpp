#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t, g, i, n, q;
    std::cin >> t;
    while (t--) {
        std::cin >> g;
        while (g--) {
            std::cin >> i >> n >> q;
            if (i == q) {
                std::cout << (n >> 1) << "\n";
            } else {
                std::cout << ((n + 1) >> 1) << "\n";
            }
        }
    }

    return 0;
}
