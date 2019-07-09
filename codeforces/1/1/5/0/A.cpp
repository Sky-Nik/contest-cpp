#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    sort(begin(s), end(s));
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(begin(b), end(b), greater<>());
    int i = 0;
    int a = 0;
    while (i < n && i < m && r >= s[i] && s[i] < b[i]) {
        r -= s[i];
        a += b[i];
    }
    cout << a + r;
    return 0;
}
