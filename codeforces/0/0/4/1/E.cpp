#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int k = n >> 1;

    std::cout << k * (n - k) << "\n";

    for (int i = 0; i < k; ++i) {
        for (int j = k; j < n; ++j) {
            std::cout << i + 1 << " " << j + 1 << "\n";
        }
    }

    return 0;
}
