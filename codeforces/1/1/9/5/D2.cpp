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
const int L = 11;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> a(n);
  cin >> a;
  vector<ll> pow10(L << 1, 1);
  fore(i, 1, L << 1) {
    pow10[i] = (10 * pow10[i - 1]) % mod;
  }
  vector<ll> cnt(L, 0);
  forn(i, n) {
    ll b = a[i], d = 0;
    while (b > 0) {
      b /= 10;
      ++d;
    }
    ++cnt[d];
  }
  ll ans = 0ll;
  forn(i, n) {
    fore(d, 1, L) {
      ll lj = 1, rj = 0, lans = 0, rans = 0, b = a[i];
      forn(k, d) {
        lans = (lans + cnt[d] * pow10[lj] * (b % 10)) % mod;
        rans = (rans + cnt[d] * pow10[rj] * (b % 10)) % mod;
        lj += 2; rj += 2; b /= 10;
      } 
      --lj;
      while (b > 0) {
        lans = (lans + cnt[d] * pow10[lj] * (b % 10)) % mod;
        rans = (rans + cnt[d] * pow10[rj] * (b % 10)) % mod;
        ++lj; ++rj; b /= 10;
      }
      ans = (ans + lans + rans) % mod;
    }
  }
  cout << ans;
  return 0;
}