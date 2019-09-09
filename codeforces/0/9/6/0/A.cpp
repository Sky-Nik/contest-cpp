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
    string s;
	cin >> s;
    int ka = 0, kb = 0, kc = 0, i = 0;
    while (i < s.length() && s[i] == 'a') {
    	++i;
    	++ka;
    }
    while (i < s.length() && s[i] == 'b') {
    	++i;
    	++kb;
    }
    while (i < s.length() && s[i] == 'c') {
    	++i;
    	++kc;
    }
    if (ka + kb + kc == s.length() && ka != 0 && kb != 0 && (ka == kc || kb == kc)) {
    	cout << "YES";
    } else {
    	cout << "NO";
    }
	return 0;
}
