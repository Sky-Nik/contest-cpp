#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    ll s = 0;
    int m = 0;
    for (int i = 0, l; i < n; ++i) {
        cin >> l;
        s += l;
        m = max(m, l);
    }
    cout << (m << 1) - s + 1;
    return 0;
}