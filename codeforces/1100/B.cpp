#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int main() {
  int n, m;
  cin >> n >> m;
  vi a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
    --a[i];
  }
  int mi = 0, mi_co = n;
  vi co(n, 0);
  string ans = "";
  for (int i = 0; i < m; ++i) {
    //cout << "DEBUG a[i] = " << a[i] << ", mi = " << mi << ", mi_co = " << mi_co << "\n";
    if (co[a[i]] == mi) {
      --mi_co;
      ++co[a[i]];
      if (mi_co == 0) {
        ans += "1";
        ++mi;
        mi_co = count(co.begin(), co.end(), mi);
      } else {
        ans += "0";
      }
    } else {
      ans += "0";
      ++co[a[i]];
    }
  }
  cout << ans;
  return 0;
}