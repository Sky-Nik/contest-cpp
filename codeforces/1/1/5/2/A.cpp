#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int a0 = 0, a1 = 0, b0 = 0, b1 = 0;
    for (int i = 0, ai; i < n; ++i) {
        cin >> ai;
        if (ai & 1) {
            ++a1;
        } else {
            ++a0;
        }
    }
    for (int i = 0, bi; i < m; ++i) {
        cin >> bi;
        if (bi & 1) {
            ++b1;
        } else {
            ++b0;
        }
    }
    cout << min(a1, b0) + min(a0, b1);
    return 0;
}