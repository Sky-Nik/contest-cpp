/* INPUT
5
4
2 2 3
2 1 2
2 3 4
1 3
2
0
0
3
3 1 2 3
3 1 2 3
3 1 2 3
1
1 1
4
1 1
1 2
1 3
1 4
->
IMPROVE
4 4
IMPROVE
1 1
OPTIMAL
OPTIMAL
OPTIMAL
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t --> 0) {
        int n;
        cin >> n;

        vector<vector<int>> g(n);
        for (auto& r : g) {
            int k;
            cin >> k;
            r.resize(k);
            for (auto& e : r) {
                cin >> e;
                --e;
            }
        }

        vector<bool> used(n);
        int last_not_married = -1;
        for (int j = 0; j < n; ++j) {
            bool married = false;
            for (auto e : g[j]) {
                if (!used[e]) {
                    used[e] = true;
                    married = true;
                    break;
                }
            }
            if (!married) {
                last_not_married = j;
            }
        }

        if (last_not_married == -1) {
            cout << "OPTIMAL\n";
        } else {
            cout << "IMPROVE\n";
            for (int i = 0; i < n; ++i) {
                if (!used[i]) {
                    cout << last_not_married + 1 << " " << i + 1 << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}
