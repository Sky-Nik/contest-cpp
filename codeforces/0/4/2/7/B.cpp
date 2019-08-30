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
    int n, t, c, s, answer = 0;
    cin >> n >> t >> c;
    vector<int> g(n);
    forn(i, n) {
    	cin >> g[i];
    	g[i] = g[i] <= t;
    }
    auto p = begin(g);
    advance(p, c);
    s = accumulate(begin(g), p, 0);
    fore(i, c, n) {
    	if (s == c) ++answer;
    	s -= g[i - c];
    	s += g[i];
    }
	if (s == c) ++answer;
    cout << answer;
    return 0;
}
