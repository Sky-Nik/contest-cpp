#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s, m = 0, sum = 0;
    cin >> n >> s;
    for (int i = 0, a; i < n; ++i) {
        cin >> a;
        m = max(m, a);
        sum += a;
    }
    if (sum - m <= s) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}