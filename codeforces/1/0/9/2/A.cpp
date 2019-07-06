#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0, n, k; i < t; ++i) {
        cin >> n >> k;
        for (int j = 0; j < n; ++j) {
            cout << (char)('a' + (j % k));
        }
        cout << "\n";
    }
    return 0;
}