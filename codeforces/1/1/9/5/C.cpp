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

template<typename T>
T max_(T t) {
  return t;
}

template<typename T, typename... Args>
T max_(T t, Args... args) {
  return max(t, max_(args...));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<ll>> h(2, vector<ll>(n));
  cin >> h[0] >> h[1];
  vector<vector<ll>> dp(2, vector<ll>(n + 1, 0));
  forn(i, n) {
    forn(j, 2) {
      dp[j][i + 1] = h[j][i] + max_(
        dp[j^1][i], 
        (i == 0) ? 0 : dp[j][i - 1], 
        (i == 0) ? 0 : dp[j^1][i - 1]
      );
    }
  }
  cout << max(dp[0][n], dp[1][n]);
  return 0;
}