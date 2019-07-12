#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define elif else if
#define forn(i, n) for(ll i = 0; i < n; ++i)
#define fore(i, l, r) for(ll i = l; i < r; ++i)
//#define sum(a) accumulate(begin(a), end(a), 0ll)

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
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> s(n);
    cin >> s;
    sort(begin(s) + 1, end(s));
    ll sum = 0ll;
    ll i = 0;
    for (; i < n; ++i) {
        sum += s[i];
        if (s[0] * a < b * sum) {
            break;
        }
    }
    cout << (n - i);
    return 0;
}