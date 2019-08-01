#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i = 0; i < n; ++i)

template<typename T>
inline istream& operator >> (istream& is, vector<T>& v) {
  for (auto& e: v) {
    cin >> e;
  }
  return is;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  cin >> a;
  vector<int> f(k, 0);
  forn(i, n) {
    ++f[a[i] - 1];
  }
  int ans = 0;
  forn(i, k) {
    ans += (f[i] >> 1) << 1;
    n -= (f[i] >> 1) << 1;
    f[i] %= 2;
  }
  forn(i, k) {
    if ((f[i] & 1) && n > 0) {
      ++ans;
      --f[i];
      n -= 2;
    }
  }
  cout << ans;
  return 0;
}