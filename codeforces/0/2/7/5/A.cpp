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
    vector<vector<int>> adj{
    	{0, 1, 3},
    	{1, 0, 2, 4},
    	{2, 1, 5},
    	{3, 0, 4, 6},
    	{4, 1, 3, 5, 7},
    	{5, 2, 4, 8},
    	{6, 3, 7},
    	{7, 4, 6, 8},
    	{8, 5, 7}
    };
    vector<int> k(9);
    vector<int> b(9, 1);
    cin >> k;
    forn(i, 9) if (k[i] & 1) forn(j, size(adj[i])) b[adj[i][j]] = 1 - b[adj[i][j]];
    forn(i, 3) {
    	forn(j, 3) cout << b[3 * i + j];
    	cout << "\n";
	}
    return 0;
}