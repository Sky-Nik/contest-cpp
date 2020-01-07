#include <bits/stdc++.h>
using namespace std;
#define forn(_forn_i, _forn_n) for (int _forn_i = 0; _forn_i < _forn_n; ++_forn_i)
int n, c, r;
const int kMaxN = 100'000;
int t[kMaxN], a[kMaxN], d[kMaxN];
stack<int> p[kMaxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    forn(i, n) cin >> t[i];
    forn(i, n) cin >> a[i];
    forn(i, n) --a[i];
    forn(i, n) if (a[i] != -1) ++d[a[i]];
    forn(i, n) if (t[i]) {
        c = i;
        while (a[c] != -1 && d[a[c]] == 1) {
            p[i].push(c);
            c = a[c];
        }
        p[i].push(c);
    }
    forn(i, n) if (p[i].size() > p[r].size()) r = i;
    cout << p[r].size() << "\n";
    while (!p[r].empty()) {
        cout << p[r].top() + 1 << " ";
        p[r].pop();
    }
    return 0;
}
