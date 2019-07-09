#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
#define sort(v) sort(begin(v), end(v))

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
    ll a, b, x, y, z;
    cin >> a >> b >> x >> y >> z;
    cout << max(2 * x + y - a, 0ll) + max(y + 3 * z - b, 0ll);
    return 0;
}