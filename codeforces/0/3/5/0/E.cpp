#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;
    
    std::vector<int> marked(k);
    std::vector<bool> is_marked(n, false);
    for (auto& ai: marked) {
        std::cin >> ai;
        --ai;
        is_marked[ai] = true;
    }

    if (k == n || m > n * (n - 1) / 2 - k + 1) {
        std::cout << -1;
    } else {
        std::vector<std::vector<bool>> e(n, std::vector<bool>(n, false));

        int x = marked[0], y = !x;

        for (int i = y + 1; i < n; ++i) {
            if (i != x) {
                y += (y == x);
                e[y][i] = true;
                e[i][y] = true;
                --m;
                std::cout << y + 1 << " " << i + 1 << "\n";
                ++y;
            }
        }

        for (int i = 0; i < n && m; ++i) {
            if (!is_marked[i]) {
                e[x][i] = true;
                e[i][x] = true;
                --m;
                std::cout << x + 1 << " " << i + 1 << "\n";
            }
        }

        for (int i = 0; i < n && m; ++i) {
            if (i != x) {
                for (int j = i + 1; j < n && m; ++j) {
                    if (j != x && !e[i][j]) {
                        e[i][j] = 1;
                        e[j][i] = 1;
                        --m;
                        std::cout << i + 1 << " " << j + 1 << "\n";
                    }
                }
            }
        }
    }

    return 0;
}
