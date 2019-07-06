#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(begin(a), end(a));
    int ans = 0;
    for (int i = 0; i < n; i += 2) {
        ans += a[i + 1] - a[i];
    }
    cout << ans;
    return 0;
}