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
    int n;
    cin >> n;
    vector<int> w(n), h(n);
    forn(i, n) cin >> w[i] >> h[i];
    int c = max(w[0], h[0]);
    bool p = true;
    fore(i, 1, n) {
    	if (c >= max(w[i], h[i])) {
    		c = max(w[i], h[i]);
    	} elif (c >= min(w[i], h[i])) {
    		c = min(w[i], h[i]);
    	} else {
    		p = false;
    	}
    }
    if (p) {
    	cout << "YES";
    } else {
    	cout << "No";
    }
    return 0;
}