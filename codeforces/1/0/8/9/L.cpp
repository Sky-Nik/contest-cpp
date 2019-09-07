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
        is >> e;
    }
    return is;
}

template<typename T>
inline ostream& operator << (ostream& os, const vector<T>& v) {
    for (const auto& e: v) {
        os << e << " ";
    }
     os << "\n";
    return os;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, i = 0;
    ll answer = 0;
    cin >> n >> k;
    vector<pii> ab(n);
    vector<int> f(k, 0);
    forn(i, n) {
    	cin >> ab[i].second;
    	--ab[i].second;
    }
    forn(i, n) cin >> ab[i].first;
    sort(begin(ab), end(ab));
    forn(i, n) ++f[ab[i].second];
    int l = count_if(begin(f), end(f), [](int x) { return x == 0; } );
    while (i < n) {
    	if (l == 0) {
    		break;
    	} else {
    		while (f[ab[i].second] == 1) {
    			++i;
    		}
    		answer += ab[i].first;
    		--f[ab[i].second];
    		++i;
    		--l;
    	}
    }
    cout << answer;
    return 0;
}
