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
    int n;
    cin >> n;
    vector<pii> a(2 * n);
    forn(i, 2 * n) {
    	cin >> a[i].first;
    	a[i].second = i;
    }
    sort(begin(a), end(a));
    ll answer = a[0].second + a[1].second;
    forn(i, n - 1) {
    	answer += min(
    		abs(a[2 * i].second - a[2 * i + 2].second) +
    		abs(a[2 * i + 1].second - a[2 * i + 3].second),
			abs(a[2 * i].second - a[2 * i + 3].second) +
			abs(a[2 * i + 1].second - a[2 * i + 2].second)
		);
    }
    cout << answer;
    return 0;
}
