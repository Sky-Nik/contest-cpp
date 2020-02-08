#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<int>> board(n, std::vector<int>(m));
    for (auto& row : board) {
        for (auto& elem : row) {
            char c;
            std::cin >> c;
            elem = c - '0';
        }
    }

    std::vector<std::vector<std::vector<int>>>
        dp(n, std::vector<std::vector<int>>(m, std::vector<int>(k + 1, -1)));

    std::vector<std::vector<std::vector<char>>>
        from(n, std::vector<std::vector<char>>(m, std::vector<char>(k + 1, '.')));

    for (int col = 0; col < m; ++col) {
        dp[0][col][board[0][col] % (k + 1)] = board[0][col];
    }

    for (int row = 1; row < n; ++row) {
        for (int col = 0; col < m; ++col) {
            for (int ell = 0; ell <= k; ++ell) {
                if (col != 0) {
                    if (dp[row - 1][col - 1][ell] != -1) {
                        int ell_ = (ell + board[row][col]) % (k + 1);
                        int dp_ = dp[row - 1][col - 1][ell] + board[row][col];
                        if (dp[row][col][ell_] < dp_) {
                            dp[row][col][ell_] = dp_;
                            from[row][col][ell_] = 'L';
                        }
                    }
                }

                if (col != m - 1) {
                    if (dp[row - 1][col + 1][ell] != -1) {
                        int ell_ = (ell + board[row][col]) % (k + 1);
                        int dp_ = dp[row - 1][col + 1][ell] + board[row][col];
                        if (dp[row][col][ell_] < dp_) {
                            dp[row][col][ell_] = dp_;
                            from[row][col][ell_] = 'R';
                        }
                    }
                }
            }
        }
    }

    // // Debug
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         for (int ell = 0; ell <= k; ++ell) {
    //             std::cout << dp[i][j][ell] << " ";
    //         }
    //         std::cout << "\n";
    //     }
    //     std::cout << "\n";
    // }

    // // Debug
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         for (int ell = 0; ell <= k; ++ell) {
    //             std::cout << from[i][j][ell] << " ";
    //         }
    //         std::cout << "\n";
    //     }
    //     std::cout << "\n";
    // }

    int max_peas = -1, starting_col = -1;

    for (int col = 0; col < m; ++col) {
        if (dp[n - 1][col][0] > max_peas) {
            max_peas = dp[n - 1][col][0];
            starting_col = col;
        }
    }

    if (max_peas == -1) {
        std::cout << -1;
        return 0;
    }

    std::string path;
    int col = starting_col, ell = 0;

    for (int row = n - 1; row > 0; --row) {
        // std::cout << "row = " << row << ", col = " << col << ", ell = " << ell << "\n";  // Debug
        if (from[row][col][ell] == 'L') {
            path += 'L';
            ell = (((ell - board[row][col]) % (k + 1)) + k + 1) % (k + 1);
            col -= 1;
        } else if (from[row][col][ell] == 'R') {
            path += 'R';
            ell = (((ell - board[row][col]) % (k + 1)) + k + 1) % (k + 1);
            col += 1;
        } else {
            std::cout << "What the hell?\n";
        }
    }

    std::cout << max_peas << "\n" << starting_col + 1 << "\n" << path;

    return 0;
}
