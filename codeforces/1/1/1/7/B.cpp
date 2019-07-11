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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    cin >> a;
    sort(begin(a), end(a));
    ll f, s = m / (k + 1);
    f = m - s;
    cout << f * a[n - 1] + s * a[n - 2];
    return 0;
}