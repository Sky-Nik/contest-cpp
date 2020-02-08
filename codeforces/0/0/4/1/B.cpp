#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> ComputeSuffixMax(const std::vector<int>& a, int n) {
    std::vector<int> suffix_max(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        suffix_max[i] = std::max(suffix_max[i + 1], a[i]);
    }
    return suffix_max; 
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, b;
    std::cin >> n >> b;

    std::vector<int> a(n);
    for (auto& ai : a) {
        std::cin >> ai;
    }

    std::vector<int> suffix_max = ComputeSuffixMax(a, n);

    int max_profit = 0;

    for (int day = 0; day < n; ++day) {
        int can_buy = b / a[day];
        max_profit = std::max(max_profit, (suffix_max[day] - a[day]) * can_buy);
    }

    std::cout << max_profit + b;

    return 0;
}