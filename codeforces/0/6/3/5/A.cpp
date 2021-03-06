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
//    os << v.size() << "\n";
    for (const auto& e: v) {
        os << e << " ";
    }
    os << "\n";
    return os;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c, n, k, xi, yi, answer = 0;
    cin >> r >> c >> n >> k;
    vector<vector<int>> s(r, vector<int>(c, 0));
    while (n --> 0) {
        cin >> xi >> yi;
    	s[xi - 1][yi - 1] = 1;
    }
    vector<vector<int>> p(r + 1, vector<int>(c + 1, 0));
    forn(r1, r) {
    	forn(c1, c) {
    		p[r1 + 1][c1 + 1] = p[r1][c1 + 1] + p[r1 + 1][c1] - p[r1][c1] + s[r1][c1];
    	}
    }
    forn(r1, r) {
    	forn(c1, c) {
    		fore(r2, r1, r) {
				fore(c2, c1, c) {
					if (p[r2 + 1][c2 + 1] - p[r1][c2 + 1] - p[r2 + 1][c1] + p[r1][c1] >= k) {
						++answer;
					}
				}
			}
    	}
    }
    cout << answer;
    return 0;
}
