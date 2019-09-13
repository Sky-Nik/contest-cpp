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
    string s;
    cin >> n >> m;
    map<string, int> k;
    forn(i, n) {
        cin >> s;
    	k[s] = 1;
    }
    forn(i, m) {
        cin >> s;
    	if (k.find(s) == k.end()) {
    		k[s] = 0;
    	}
    	k[s] += 2;
    }
    int a = 0, b = 0, c = 0;
    for (const auto& [si, v]: k) {
    	if (v == 1) {
    		++a;
    	} elif (v == 2) {
    		++b;
    	} else {
    		++c;
    	}
    }
    if (a + (c + 1) / 2 > b + c / 2) {
    	cout << "YES";
    } else {
    	cout << "NO";
    }
    return 0;
}
