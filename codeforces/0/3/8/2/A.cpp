#include <bits/stdc++.h>
using namespace std;

//typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
//typedef pair<ll, int> pli;
//typedef pair<int, ll> pil;
//typedef pair<ll, ll> pll;

#define elif else if
#define forn(_i, _n) for(int _i = 0; _i < static_cast<int>(_n); ++_i)
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
    string s, t;
    cin >> s >> t;
    int l = distance(begin(s), find(begin(s), end(s), '|'));
    int r = s.length() - l - 1;
    if (((s.length() + t.length()) & 1) && (abs(r - l) <= t.length())) {
    	int ll = max(0, r - l), rr = max(0, l - r), tl = t.length();
    	tl -= abs(r - l);
    	ll += (tl >> 1);
    	rr += (tl >> 1);
    	cout << t.substr(0, ll) + s + t.substr(ll, rr);
    } else {
    	cout << "Impossible";
    }
    return 0;
}
