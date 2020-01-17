#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n, m, c, xi, yi, pi, lower = 0, upper = 0;
    cin >> n >> m >> c;
    for (int i = 0; i < n; ++i) {
        cin >> xi >> yi >> pi;
        if (yi < m * xi + c)
            lower += pi;
        else
            upper += pi;
    }

    cout << max(lower, upper);

    return 0;
}
