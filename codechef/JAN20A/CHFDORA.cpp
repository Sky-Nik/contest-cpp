#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --> 0) {
        int n, m;
        cin >> n >> m;

        vector<vector<int64_t>> a(n, vector<int64_t>(m));
        for (auto& r: a)
            for (auto& c: r)
                cin >> c;

        int64_t answer = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int d = 1;
                
                while (0 <= i - d && i + d < n && a[i - d][j] == a[i + d][j] &&
                    0 <= j - d && j + d < m && a[i][j - d] == a[i][j + d])
                    ++d;

                answer += d;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
