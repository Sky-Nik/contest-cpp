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

bool won(const vector<string>& b) {
	forn(i, 4) {
		forn(j, 2) {
			if (b[i][j] == 'x' && b[i][j + 1] == 'x' && b[i][j + 2] == 'x') {
				return true;
			}
		}
	}
	forn(i, 2) {
		forn(j, 4) {
			if (b[i][j] == 'x' && b[i + 1][j] == 'x' && b[i + 2][j] == 'x') {
				return true;
			}
		}
	}
	forn(i, 2) {
		forn(j, 2) {
			if (b[i][j] == 'x' && b[i + 1][j + 1] == 'x' && b[i + 2][j + 2] == 'x') {
				return true;
			}
		}
	}
	fore(i, 2, 4) {
		forn(j, 2) {
			if (b[i][j] == 'x' && b[i - 1][j + 1] == 'x' && b[i - 2][j + 2] == 'x') {
				return true;
			}
		}
	}
	return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> b(4);
    cin >> b;
    bool p = false;
    forn(i, 4) {
    	forn(j, 4) {
    		if (b[i][j] == '.') {
    			b[i][j] = 'x';
    			if (won(b)) {
    				p = true;
    			}
    			b[i][j] = '.';
    		}
    	}
    }
    if (p) {
    	cout << "YES";
    } else {
    	cout << "NO";
    }
    return 0;
}
