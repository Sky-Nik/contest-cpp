#include <iostream>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t, n, s;
    std::cin >> t;
    while (t--) {
        int c = std::numeric_limits<int>::max(), k = 0;
        std::cin >> n;
        while (n--) {
            std::cin >> s;
            if (c >= s) {
                c = s;
                ++k;
            }
        }
        std::cout << k << "\n";
    }

    return 0;
}
