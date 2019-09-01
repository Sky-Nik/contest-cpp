#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

#define elif else if
#define forn(_i, _n) for(int _i = 0; _i < static_cast<int>(_n); ++_i)
#define fore(_i, _l, _r) for(int _i = _l; _i < _r; ++_i)
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
    int n, a1 = 0, a2 = 0, qs = 0;
    cin >> n;
    vector<int> t(n), c(n);
    forn(i, n) {
    	cin >> t[i] >> c[i];
    }
    qs = c[0];
    a1 = t[0] + c[0];
    a2 = c[0];
    fore(i, 1, n) {
    	qs = max(0, qs - (t[i] - t[i - 1]));
    	qs += c[i];
    	a2 = max(a2, qs);
    	a1 = t[i] + qs;
    }
    cout << a1 << " " << a2;
    return 0;
}
