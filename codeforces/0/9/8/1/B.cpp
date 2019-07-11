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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), x(n);
    forn(i, n) {
        cin >> a[i] >> x[i];
    }
    int m;
    cin >> m;
    vector<int> b(m), y(m);
    forn(i, m) {
        cin >> b[i] >> y[i];
    }
    map<int, int> mp;
    forn(i, n) {
        mp[a[i]] = x[i];
    }
    forn(i, m) {
        if (mp.find(b[i]) == mp.end()) {
            mp[b[i]] = 0;
        }
        mp[b[i]] = max(y[i], mp[b[i]]);
    }
    ll ans = 0ll;
    for (const auto& [e, p]: mp) {
        ans += static_cast<ll>(p);
    }
    cout << ans;
    return 0;
}