#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& pi: p)
        cin >> pi;

    int inv_count = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            inv_count += p[i] > p[j];
   
    // cout << inv_count << "\n";

    vector<vector<int>> l(n, vector<int>(n, 0));
    for (int j = 1; j < n; ++j)
        l[0][j] = p[0] < j;
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < n; ++j)
            l[i][j] = l[i - 1][j] + (p[i] < j);

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << l[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    int pair_count = 0,
        min_inv_count = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (p[i] > p[j]) {
                int cur_inv_count = inv_count + 1 
                    + 2 * (l[i][p[i]] - l[i][p[j]] - l[j][p[i]] + l[j][p[j]]);

                // cout << "i = " << i << ", j = " << j << ", cur_inv_count = " << cur_inv_count << "\n"; 

                if (cur_inv_count < min_inv_count) {
                    min_inv_count = cur_inv_count;
                    pair_count = 1;
                } else if (cur_inv_count == min_inv_count) {
                    ++pair_count;
                }
            }
        }
    }

    cout << min_inv_count << " " << pair_count;

    return 0;
}
