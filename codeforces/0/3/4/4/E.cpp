#include <algorithm>
#include <iostream>
#include <vector>

bool possible(const std::vector<int64_t>& h, const std::vector<int64_t>& p, size_t n, size_t m, int64_t t) {
    size_t j = 0;
    for (size_t i = 0; i < h.size(); ++i) {
        if (j == m) {
            return true;
        }
        if (h[i] <= p[j]) {
            while (j < m && p[j] <= h[i] + t) {
                ++j;
            }
        } else {
            if (h[i] - p[j] <= t) {
                int64_t ri = std::max(t - ((h[i] - p[j]) << 1), (t - (h[i] - p[j])) >> 1);
                while (j < m && p[j] <= h[i] + ri) {
                    ++j;
                }
            }
        }
    }
    return j == m;
}

int64_t binary_search(const std::vector<int64_t>& h, const std::vector<int64_t>& p, size_t n, size_t m) {
    int64_t l = -1, t, r = 15'000'000'000LL;
    while (l + 1 != r) {
        t = (l + r) / 2;
        if (possible(h, p, n, m, t)) {
            r = t;
        } else {
            l = t;
        }
    }
    return r;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m;
    std::cin >> n >> m;
    std::vector<int64_t> h(n), p(m);
    for (auto& hi: h) std::cin >> hi;
    for (auto& pi: p) std::cin >> pi;

    std::cout << binary_search(h, p, n, m);

    return 0;
}