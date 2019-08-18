#include <bits/stdc++.h>
using namespace std;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, n, k;
  cin >> t;
  for (int ti = 0; ti < t; ++ti) {
    cin >> n >> k;
    if (k % 3 == 0) {
      n %= (k + 1);
      if (n % 3 != 0 || n == k) {
        cout << "Alice";
      } else {
        cout << "Bob";
      }
    } else {
      if (n % 3 == 0) {
        cout << "Bob";
      } else {
        cout << "Alice";
      }
    }
    cout << "\n";
  }
  return 0;
}