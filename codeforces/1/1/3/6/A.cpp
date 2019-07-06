#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }
    int k;
    cin >> k;
    int a = 0;
    for (int i = 0; i < n; ++i) {
        if (r[i] < k) {
            ++a;
        } else {
            cout << n - a;
            return 0;
        }
    }
}