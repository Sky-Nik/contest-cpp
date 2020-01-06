#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    vector<int> c(m);
    for (auto& ci: c) cin >> ci;
    int x, y;
    cin >> x >> y;

    vector<int> p(m + 1, 0);
    for (int i = 0; i < m; ++i) p[i + 1] = p[i] + c[i];

    bool found = false;
    for (int k = 0; k < m && !found; ++k) {
        int lower = p[k],
            upper = p[m] - p[k];
        if (x <= lower && lower <= y && x <= upper && upper <= y) {
            cout << k + 1;
            found = true;
        }
    }

    if (!found) cout << 0; 

    return 0;
}
