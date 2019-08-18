#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; ++i)
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int q, n, m;
  cin >> q;
  forn(i, q) {
    cin >> n >> m;
    vector<string> b(n);
    forn(j, n) {
      cin >> b[j];
    }
    vector<int> r(n, 0), c(m, 0);
    forn(j, n) {
      forn(k, m) {
        if (b[j][k] == '*') {
          ++r[j];
          ++c[k];
        }
      }
    }
    int a = n + m - 1;
    forn(j, n) {
      forn(k, m) {
        if (b[j][k] == '*') {
          a = min(a, (m - r[j]) + (m - c[k]));
        } else {
          a = min(a, (m - r[j]) + (m - c[k]) - 1);
        }
      }
    }
    cout << a << "\n";
  }
  return 0;
}