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
    int n, m, h;
    cin >> n >> m >> h;
    vector<vector<int>> answer(n, vector<int>(m, 0)), t(n, vector<int>(m));
    vector<int> a(m), b(n);
    cin >> a >> b >> t;
    forn(i, n) forn(j, m) answer[i][j] = t[i][j] ? min(a[j], b[i]) : 0;
    forn(i, n) {
    	forn(j, m) {
			cout << answer[i][j] << " ";
		}
		cout << "\n";
    }
    return 0;
}
