#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i = 0; i < n; ++i)

typedef long long ll;

ll n, k;

template<typename T>
inline istream& operator >> (istream& is, vector<T>& v) {
  for (auto& e: v) {
    cin >> e;
  }
  return is;
}

/* Binary search to find 
 * the smallest value of x 
 * with checker(x) true.
 * Typename T should model
 * totally ordered discrete set. */
template <typename T>
T binary_search_z(T lower_bound, T upper_bound, bool(*checker) (T)) {
  T middle;
  while (lower_bound < upper_bound) {
    middle = (lower_bound + upper_bound) >> 1;
    if ((*checker)(middle)) {
      upper_bound = middle;
    } else {
      lower_bound = middle + 1;
    }
  }
  return lower_bound;
}

ll cn2(ll n) {
  return (n * (n - 1)) >> 1;
}

bool checker(ll e) {
  return cn2(n - e + 1) - e <= k;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  cout << binary_search_z(0ll, n, checker);
  return 0;
}