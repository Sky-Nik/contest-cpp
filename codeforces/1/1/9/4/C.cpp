#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; ++i)
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  string s, t, p;
  forn(qi, q) {
    cin >> s >> t >> p;
    map<char, int> f;
    for (auto c: p) {
      if (f.find(c) == end(f)) {
        f[c] = 0;
      }
      ++f[c];
    }
    int i = 0, j = 0;
    bool possible = true;
    while (possible && j < t.length()) {
      if (s[i] == t[j]) {
        ++i;
        ++j;
      } else if (f.find(t[j]) != end(f) && f[t[j]] > 0) {
        --f[t[j]];
        ++j;
      } else {
        possible = false;
      }
    }
    if (i != s.length() || !possible) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}