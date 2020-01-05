#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai: a) cin >> ai;
    string s;
    cin >> s;

    int sz = 0, f = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            if (sz >= a[i]) {
                f += sz;  // all prev 0s are now 1s  
                sz = a[i];  // the only 0 is a[i] 
            } else {
                f += a[i];
            }
        } else {  // '0'
            sz += a[i];
        }
    }
    
    cout << f;

    return 0;
}
