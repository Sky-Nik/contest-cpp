#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& ai : a) { 
        std::cin >> ai;
    }

    std::sort(a.begin(), a.end());
    std::cout << a[n - 1] << " ";
    for (int i = 1; i + 1 < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << a[0];

    return 0;
}
