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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> b(4, vector<int>(n, 0));
    int i = 0;
    int r = 0, c = 0;
    while (r < n && i < m) {
		b[c][r] = i + 1;
//		cout << "b[" << c << "][" << r << "] = " << b[c][r] << "\n";
		if (c == 3) {
			++r;
		}
		c = 3 - c;
		++i;
	}
	r = 0;
	c = 1;
	while (r < n && i < m) {
		b[c][r] = i + 1;
//		cout << "b[" << c << "][" << r << "] = " << b[c][r] << "\n";
		if (c == 2) {
			++r;
		}
		c = 3 - c;
		++i;
	}
	forn(_r, n) {
		int _c = 1;
		while (_c != 4) {
			if (b[_c][_r]) {
				cout << b[_c][_r] << " ";
			}
			if (_c == 1) {
				_c = 0;
			} elif (_c == 0) {
				_c = 2;
			} elif (_c == 2) {
				_c = 3;
			} elif (_c == 3) {
				_c = 4;
			}
		}
	}
    return 0;
}
