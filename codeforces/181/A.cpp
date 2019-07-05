#include <bits/stdc++.h>
using namespace std;
int n, m;
const int MAXN = 100 + 10;
bool city[MAXN][MAXN];
int main() {
    cin >> n >> m;
    char c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c;
            if (c == '*') {
                city[i][j] = true;
            } else {
                city[i][j] = false;
            }
        }
    }
    bool found = false;
    int answer_h, answer_v;
    for (int h1 = 0; !found && (h1 < n); ++h1) {
        for (int v1 = 0; !found && (v1 < m); ++v1) {
            if (city[h1][v1]) {
                for (int h2 = 0; !found && (h2 < n); ++h2) {
                    if (city[h2][v1]) {
                        for (int v2 = 0; !found && (v2 < m); ++v2) {
                            if (city[h1][v2]) {
                                if (!city[h2][v2]) {
                                    found = true;
                                    answer_h = h2;
                                    answer_v = v2;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (found) {
        cout << answer_h + 1 << " " << answer_v + 1;
    } else {
        cout << -1;
    }
    return 0;
}