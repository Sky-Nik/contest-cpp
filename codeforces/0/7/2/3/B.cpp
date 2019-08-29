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
    int n;
    string s;
    cin >> n >> s;
    s += '_';
    int al = 0, ab = 0, current = 0, b = 0;
    forn(i, n + 1) {
    	if (s[i] == '_' || s[i] == ')' || s[i] == '(') {
    		if (!b) al = max(al, current);
    		elif (current) ++ab;
    		current = 0;
    		if (s[i] == ')') --b;
    		if (s[i] == '(') ++b;
    	} else {
    		++current;
    	}
    }
    cout << al << " " << ab << "\n";
    return 0;
}