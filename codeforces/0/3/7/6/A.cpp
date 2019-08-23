#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

#define elif else if
#define forn(_i, _n) for(ll _i = 0; _i < _n; ++_i)
#define fore(_i, _l, _r) for(ll _i = _l; _i < _r; ++_i)
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
    string s;
    cin >> s;
    ll p = distance(begin(s), find(begin(s), end(s), '^'));
    ll l = 0, r = 0;
    forn(i, p) if (s[i] != '=') l += (p - i) * (s[i] - '0');
	fore(i, p + 1, s.length()) if (s[i] != '=') r += (i - p) * (s[i] - '0');
    if (l < r) {
    	cout << "right";
    } elif (l == r) {
    	cout << "balance";
    } else {
    	cout << "left";
    }
    return 0;
}