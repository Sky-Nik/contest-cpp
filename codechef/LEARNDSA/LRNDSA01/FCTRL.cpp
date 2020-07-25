#include <iostream>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t, n;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        int z = 0;
        while (n) {
            n /= 5;
            z += n;
        }
        std::cout << z << "\n";
    }

    return 0;
}
