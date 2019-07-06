#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int l = 0, r = 0;
    for (int i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        if (x < 0) {
            ++l;
        } else {
            ++r;
        }
    }
    if (l <= 1 || r <= 1) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}