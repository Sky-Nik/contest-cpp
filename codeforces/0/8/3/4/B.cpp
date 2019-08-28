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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<pii> e;
    forn(i, 26) {
    	auto p = find(begin(s), end(s), static_cast<char>('A' + i));
    	if (p != end(s)) {
    		e.push_back(make_pair(distance(begin(s), p), 0));
    	}
    }
    forn(i, 26) {
    	auto p = find(rbegin(s), rend(s), static_cast<char>('A' + i));
    	if (p != rend(s)) {
    		e.push_back(make_pair(distance(p, rend(s)) - 1, 1));
    	}
    }
    sort(begin(e), end(e));
    bool p = true;
    for (auto [d, t]: e) {
    	if (t) {
    		++k;
    	} else { // if !t
    		--k;
    	}
    	p &= k >= 0;
    }
    if (p) {
    	cout << "NO";
    } else {
    	cout << "YES";
    }
    return 0;
}