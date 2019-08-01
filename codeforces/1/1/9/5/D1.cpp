#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, l, r) for(int i = l; i < r; ++i)
#define sum(a) accumulate(begin(a), end(a), 0ll)

template<typename T>
inline istream& operator >> (istream& is, vector<T>& v) {
  for (auto& e: v) {
    cin >> e;
  }
  return is;
}

const ll mod = 998244353;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> a(n);
  cin >> a;
  vector<ll> pow10(20, 1);
  fore(i, 1, 20) {
    pow10[i] = (10 * pow10[i - 1]) % mod;
  }
  ll ans = 0ll;
  forn(i, n) {
    ll j = 0;
    while (a[i] > 0) {
      ans += (a[i] % 10) * (pow10[j << 1] + pow10[(j << 1)|1]);
      ++j;
      a[i] /= 10;
      ans %= mod;
    }
  }
  ans *= n;
  cout << ans % mod;
  return 0;
}