#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(begin(a), end(a));
        if (a[0] + k < a[n - 1] - k) {
            cout << -1 << "\n";
        } else {
            cout << a[0] + k << "\n";
        }
    }
    return 0;
}