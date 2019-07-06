#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> s(n), p(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        p[i + 1] = p[i] + s[i];
    }
    int q;
    cin >> q;
    for (int i = 0, l, r; i < q; ++i) {
       cin >> l >> r;
       cout << (p[r] - p[l - 1]) / 10 << "\n";
    }
    return 0;
}