#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define elif else if
#define forn(i, n) for(ll i = 0; i < n; ++i)
#define fore(i, l, r) for(ll i = l; i < r; ++i)
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
    ll n;
    cin >> n;
    ll a = 1ll;
    fore(k, 1, 11) {
        ll d = (1ll << (k - 1)) * ((1ll << k) - 1ll);
        if (n % d == 0) {
            a = d;
        }
    }
    cout << a;
    return 0;
}