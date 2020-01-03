#include <bits/stdc++.h>
using namespace std;
int v, m = 1'000'000;
vector<int> a(9);
char c;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> v;
    for (auto& ai: a) cin >> ai;
    for (int i = 0; i < 9; ++i) if (a[i] <= m) {
        m = a[i];
        c= '1' + i;
    }
    for (int i = 0; i < v / m; ++i) s += c;
    v %= m;
    for (auto& si: s) for (char ch = '9'; ch > c; --ch) if (v >= a[ch - '1'] - a[c - '1']) {
        si = ch;
        v -= a[ch - '1'] - a[c - '1'];
        break;
    }
    if (!s.empty()) cout << s; else cout << -1;
    return 0;
}
