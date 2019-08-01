#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, l, r) for(int i = l; i < r; ++i)
#define sum(a) accumulate(begin(a), end(a), 0ll)

template< typename T>
struct min_deque {
  deque<T> q;
  T get_min() {
    return q.front();
  }
  void push(T elem) {
    while (!q.empty() && q.back() > elem) {
      q.pop_back();
    }
    q.push_back(elem);
  }
  void pop(T elem) {
    if (!q.empty() && q.front() == elem) {
      q.pop_front();
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  ll g0, x, y, z;
  cin >> g0 >> x >> y >> z;
  vector<vector<ll>> h(n, vector<ll>(m)); h[0][0] = g0;
  forn(i, n) {
    if (i > 0) {
      h[i][0] = (h[i - 1][m - 1] * x + y) % z;
    }
    fore(j, 1, m) {
      h[i][j] = (h[i][j - 1] * x + y) % z;
    }
  }
  // forn(i, n) {
  //   forn(j, m) {
  //     cout << h[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";
  vector<vector<ll>> mn(n, vector<ll>(m));
  forn(j, m) {
    min_deque<ll> q;
    forn(i, n) {
      if (i >= a) {
        q.pop(h[i - a][j]);
      }
      q.push(h[i][j]);
      mn[i][j] = q.get_min();
    }
  }
  // forn(i, n) {
  //   forn(j, m) {
  //     cout << mn[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";
  vector<vector<ll>> ans(n, vector<ll>(m));
  forn(i, n) {
    min_deque<ll> q;
    forn(j, m) {
      if (j >= b) {
        q.pop(mn[i][j - b]);
      }
      q.push(mn[i][j]);
      ans[i][j] = q.get_min();
    }
  }
  // forn(i, n) {
  //   forn(j, m) {
  //     cout << ans[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";
  ll answer = 0ll;
  fore(i, a - 1, n) {
    fore(j, b - 1, m) {
      answer += ans[i][j];
    }
  }
  cout << answer;
  return 0;
}