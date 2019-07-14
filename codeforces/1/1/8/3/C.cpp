#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll k, n, a, b;
        cin >> k >> n >> a >> b;
        if (n * b >= k) {
            cout << -1 << "\n";
        } else {
            cout << min(n, (k - n * b - 1) / (a - b)) << "\n";
        }
    }
    return 0;
}