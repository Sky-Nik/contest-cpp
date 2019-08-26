#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

#define elif else if
#define forn(_i, _n) for(int _i = 0; _i < _n; ++_i)
#define fore(_i, _l, _r) for(int _i = _l; _i < _r; ++_i)
#define sum(a) accumulate(begin(a), end(a), 0ll)

template<typename T>
inline istream& operator >> (istream& is, vector<T>& v) {
    for (auto& e: v) {
        cin >> e;
    }
    return is;
}

// not recursive
template <typename T>
T gcd (T a, T b) {
    while (b) 
        tie(a, b) = make_pair(b, a % b);
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    ll g = gcd(x, y);
    tie(x, y) = make_pair(x / g, y / g);
    cout << min(a / x, b / y);
    return 0;
}