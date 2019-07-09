#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, s, t;
        cin >> n >> s >> t;
        cout << max(n - s, n - t) + 1 << "\n";
    }
    return 0;
}
