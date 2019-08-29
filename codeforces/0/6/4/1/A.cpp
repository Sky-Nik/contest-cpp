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
    int n, i = 0;
    string s;
    cin >> n >> s;
    vector<int> d(n);
    vector<bool> u(n, false);
    cin >> d;
    while (0 <= i && i < n && !u[i]) {
    	u[i] = true;
    	if (s[i] == '<') {
    		i -= d[i];
    	} else {
			i += d[i];
    	}
    }
    if (0 <= i && i < n && u[i]) {
    	cout << "INFINITE";
    } else {
    	cout << "FINITE";
    }
    return 0;
}