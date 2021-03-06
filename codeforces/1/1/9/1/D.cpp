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
    vector<ll> a(n);
    cin >> a;
    set<ll> sa;
    ll s = sum(a);
    if (s == 0ll) {
        cout << "cslnb";
        return 0;
    }
    ll f = ((n - 1ll) * n) >> 1ll;
    ll num_pairs = 0ll;
    forn(i, n) {
        while (sa.find(a[i]) != end(sa)) {
            if (a[i] == 0) {
                cout << "cslnb";
                return 0;
            }
            if (num_pairs) {
                cout << "cslnb";
                return 0;
            }
            --a[i];
            ++num_pairs;
        }
        sa.insert(a[i]);
    }
    if ((s - f)&1ll) {
        cout << "sjfnb";
    } else {
        cout << "cslnb";
    }
    return 0;
}