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
    int n, ai, f = 0, z = 0;
    cin >> n;
    forn(i, n) {
        cin >> ai;
    	if (ai == 5) {
    		++f;
    	} else {
    		++z;
    	}
    }
    if (z == 0) {
    	cout << -1;
    } else {
    	f = 9 * (f / 9);
    	forn(i, f) {
    		cout << 5;
    	}
    	if (f == 0) {
    		cout << 0;
    	} else {
    		forn(i, z) {
				cout << 0;
			}
    	}
    }
    return 0;
}
