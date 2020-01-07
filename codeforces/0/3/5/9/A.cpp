#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto& r: a)
        for (auto& c: r)
            cin >> c;

    bool two = false; 
    for (int r = 0; r < n; ++r)
        two |= a[r][0];
    for (int r = 0; r < n; ++r)
        two |= a[r][m - 1];
    for (int c = 0; c < m; ++c)
        two |= a[0][c];
    for (int c = 0; c < m; ++c)
        two |= a[n - 1][c];

    if (two)
        cout << 2;
    else
        cout << 4;

    return 0;
}
