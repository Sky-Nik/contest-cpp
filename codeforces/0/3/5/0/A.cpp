#include <bits/stdc++.h>
using namespace std;
int n, m, a_min, a_max, b_min, v;
const int kMaxN = 100, kMaxM = 100;
int a[kMaxN], b[kMaxM];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    a_min = *min_element(a, a + n);
    a_max = *max_element(a, a + n);
    b_min = *min_element(b, b + m);
    v = max(a_min << 1, a_max);
    if (v >= b_min) cout << -1; else cout << v;
    return 0;
}
