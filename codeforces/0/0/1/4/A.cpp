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
    int n, m;
	cin >> n >> m;
	int l = 0, r = m - 1, d = n - 1, u = 0;
	vector<string> picture(n);
	vector<int> row(n, 0), col(m, 0);
	cin >> picture;
	forn(i, n) forn(j, m) if (picture[i][j] == '*') {
		++row[i];
		++col[j];
	}
	while (row[d] == 0) --d;
	while (row[u] == 0) ++u;
	while (col[l] == 0) ++l;
	while (col[r] == 0) --r;
	fore(i, u, d + 1) {
		fore(j, l, r + 1) {
			cout << picture[i][j];
		}
		cout << "\n";
	}
    return 0;
}
