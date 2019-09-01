#include <bits/stdc++.h>
using namespace std;

//typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
//typedef pair<ll, int> pli;
//typedef pair<int, ll> pil;
//typedef pair<ll, ll> pll;

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
    int n, ll, rr;
    cin >> n;
    vector<int> l(n), r(n);
    forn(i, n) cin >> l[i] >> r[i];
    ll = *min_element(begin(l), end(l));
    rr = *max_element(begin(r), end(r));
    bool f = false;
    forn(i, n) {
    	if (l[i] == ll && r[i] == rr) {
    		cout << i + 1;
    		f = true;
    		break;
    	}
    }
    if (!f) {
    	cout << -1;
    }
    return 0;
}
