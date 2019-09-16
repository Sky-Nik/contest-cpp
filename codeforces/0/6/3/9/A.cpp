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
    os << v.size() << "\n";
    for (const auto& e: v) {
        os << e << " ";
    }
    os << "\n";
    return os;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, q, ti, idi;
    cin >> n >> k >> q;
    vector<int> t(n), l(k, -1);
    cin >> t;
    while (q --> 0) {
    	cin >> ti  >> idi;
    	--idi;
    	if (ti == 1) {
    		int idx = -1;
    		forn(i, k) {
    			if (l[i] == -1 || t[idi] > t[l[i]]) {
    				idx = i;
    				break;
    			}
    		}
    		if (idx != -1) {
    			for (int i = k; i --> idx + 1;) {
    				l[i] = l[i - 1];
    			}
    			l[idx] = idi;
    		}
    	} else {
    		bool f = false;
    		forn(i, k) {
    			if (l[i] == idi) {
    				cout << "YES\n";
    				f = true;
    			}
    		}
    		if (!f) {
    			cout << "NO\n";
    		}
    	}
    }
    return 0;
}
