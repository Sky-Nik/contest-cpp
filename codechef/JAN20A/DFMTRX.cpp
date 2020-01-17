#include <iostream>
#include <vector>

void solve(int n) {
    std::vector<std::vector<int>> a(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
        a[i][i] = 2 * n - 1;

    for (int k = 1; k < n; ++k) {
        a[k - 1][n - 1] = k;
        a[n - 1][k - 1] = k + n - 1;

        int i = k, j = k;

        for (int d = 1; d < n / 2; ++d) {
            ++i;

            if (i == n)
                i = 1;

            --j;

            if (j == 0)
                j = n - 1;

            if (i < j) {
                a[i - 1][j - 1] = k;
                a[j - 1][i - 1] = k + n - 1;
            } else {
                a[j - 1][i - 1] = k;
                a[i - 1][j - 1] = k + n - 1;
            }
        }
    }

    for (auto r: a) {
        for (auto c: r)
            std::cout << c << " ";
        std::cout << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t --> 0) {
        int n;
        std::cin >> n;

        if (n == 1) {
            std::cout << "Hooray" << "\n";
            std::cout << 1 << "\n";
        } else if (n % 2 == 1) {
            std::cout << "Boo" << "\n";
        } else {
            std::cout << "Hooray" << "\n";
            solve(n);
        }
    }

    return 0;
}