#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (auto& ai: a) cin >> ai;
    for (auto& bi: b) cin >> bi;
    for (auto& ci: c) cin >> ci;

    vector<int> dp0(n), dp1(n);
    dp0[n - 1] = a[n - 1];
    dp1[n - 1] = b[n - 1];
    
    for (int i = n - 2; i >= 0; --i) {
        dp0[i] = max(a[i] + dp1[i + 1], b[i] + dp0[i + 1]);
        dp1[i] = max(b[i] + dp1[i + 1], c[i] + dp0[i + 1]);
    }
    
    cout << dp0[0];

    return 0;
}
