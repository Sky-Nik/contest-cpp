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

template<typename U, typename V>
inline istream& operator >> (istream& is, pair<U, V>& p) {
    is >> p.first >> p.second;
    return is;
}

template<typename U, typename V>
inline ostream& operator << (ostream& os, pair<U, V>& p) {
    os <<  p.first << " " << p.second;
    os << "\n";
    return os;
}

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
    string s;
	cin >> n >> s;
	if (n == 2 || n == 3) {
		cout << s;
	} else {
		forn(i, n / 2 - 1) {
			cout << s.substr(2 * i, 2) << "-";
		}
		if (n & 1) {
			cout << s.substr(2 * (n / 2 - 1), 3) << "\n";
		} else {
			cout << s.substr(2 * (n / 2 - 1), 2) << "\n";
		}
	}
    return 0;
}
