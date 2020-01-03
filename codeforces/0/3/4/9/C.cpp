#include <bits/stdc++.h>
using namespace std;
int64_t n, ai, m, k = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        k += ai;
        m = max(m, ai);
    }
    cout << max(m, (k + n - 2) / (n - 1));
    return 0;
}
