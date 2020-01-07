#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --> 0) {
        vector<string> board(8);
        for (auto& row: board)
            cin >> row;

        int k1r = -1, k1c = -1, k2r = -1, k2c = -1;
        for (int r = 0; r < 8; ++r) {
            for (int c = 0; c < 8; ++c) {
                if (board[r][c] == 'K') {
                    if (k1r == -1) {
                        k1r = r;
                        k1c = c;
                    } else {
                        k2r = r;
                        k2c = c;
                    }
                }
            }
        }

        int dr = abs(k1r - k2r),
            dc = abs(k1c - k2c);

        if (dr % 4 != 0 || dc % 4 != 0) {
            cout << "NO\n";
        } else {
            bool possible = false;
            for (int r = 0; r < 8; ++r) {
                for (int c = 0; c < 8; ++c) {
                    if (board[r][c] != '#') {
                        int d1 = abs(r - k1r) + abs(c - k1c),
                            d2 = abs(r - k2r) + abs(c - k2c);
                        if (d1 % 4 == 0 && d2 % 4 == 0) {
                            possible = true;
                        }
                    }
                }
            }

            if (possible)
                cout << "YES\n";
            else
                cout << "NO\n";
        }

    }

    return 0;
}
