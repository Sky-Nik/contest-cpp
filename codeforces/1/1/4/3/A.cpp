#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    bool k0 = false, k1 = false;
    for (int i = n - 1; i >= 0; --i) {
        if (b[i]) {
            k1 = true;
        } else {
            k0 = true;
        }
        if (k1 && k0) {
            cout << i + 1;
            return 0;
        }
    }
}