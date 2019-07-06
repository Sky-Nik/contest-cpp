#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0, l, r; i < t; ++i) {
        cin >> l >> r;
        cout << l << " " << (l << 1) << "\n";
    }
    return 0;
}