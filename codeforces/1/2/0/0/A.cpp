#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, l, r) for(int i = l; i < r; ++i)
#define sum(a) accumulate(begin(a), end(a), 0ll)

template<typename T>
inline ostream& operator << (ostream& os, const vector<T>& v) {
    for (const auto& e: v) {
        cout << e;
    }
    cout << "\n";
    return os;
}

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
    vector<bool> r(10);
    int n;
    string s;
    cin >> n >> s;
    for (char c: s) {
    	if (c == 'L') {
    		forn(i, 10) {
    			if (!r[i]) {
    				r[i] = true;
    				break;
    			}
    		}
    	} elif (c == 'R') {
    		for (int i = 10; i --> 0;) {
    			if (!r[i]) {
    				r[i] = true;
    				break;
    			}
    		}
    	} else {
    		r[c - '0'] = false;
    	}
      //cout << r;
    }
    cout << r;
    return 0;
}