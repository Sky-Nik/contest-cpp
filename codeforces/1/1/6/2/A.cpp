#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, h, m;
    cin >> n >> h >> m;
    vector<int> max_h(n, h);
    for (int i = 0, li, ri, xi; i < m; ++i) {
        cin >> li >> ri >> xi;
        --li;
        --ri;
        for (int j = li; j <= ri; ++j) {
            max_h[j] = min(max_h[j], xi);
        }
    }
    int a = 0;
    for (int i = 0; i < n; ++i) {
        a += max_h[i] * max_h[i];
    }
    cout << a;
    return 0;
}