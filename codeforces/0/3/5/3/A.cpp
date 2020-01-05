#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    int sx = accumulate(x.begin(), x.end(), 0),
        sy = accumulate(y.begin(), y.end(), 0);

    bool swappable = false;
    for (int i = 0; i < n; ++i) swappable |= ((x[i] + y[i]) & 1);

    if ((sx + sy) & 1) {
        cout << -1;
    } else if ((sx & 1) || (sy & 1)) {
        if (swappable) {
            cout << 1;
        } else {
            cout << -1;
        }
    } else {
        cout << 0;
    }

    return 0;
}
