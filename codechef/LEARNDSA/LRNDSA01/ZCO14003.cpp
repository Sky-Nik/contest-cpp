#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int64_t> b(n);
    for (auto& bi : b) {
        std::cin >> bi;
    }
    std::sort(b.begin(), b.end());
    int64_t a = 0;
    for (int i = 0; i < n; ++i) {
        a = std::max(a, b[i] * (n - i));
    }
    std::cout << a;
    return 0;
}
