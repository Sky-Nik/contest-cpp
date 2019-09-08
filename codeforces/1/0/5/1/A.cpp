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
    int t;
    string s;
    cin >> t;
    while (t --> 0) {
    	cin >> s;
    	int a = 0, b = 0, c = 0;
    	forn(i, s.length()) {
    		if (islower(s[i])) {
    			++a;
    		} elif (isupper(s[i])) {
    			++b;
    		} else { // if (isdigit(s[i]))
    			++c;
    		}
    	}
    	if (a) {
    		if (b) {
    			if (c) {
    				; // pass
    			} else {
    				if (a > 1) {
    					forn(i, s.length()) {
    						if (islower(s[i])) {
    							s[i] = '0';
    							break;
    						}
    					}
    				} else {
    					forn(i, s.length()) {
    						if (isupper(s[i])) {
    							s[i] = '0';
    							break;
    						}
    					}
    				}
    			}
    		} else {
    			if (c) {
    				if (a > 1) {
						forn(i, s.length()) {
							if (islower(s[i])) {
								s[i] = 'A';
								break;
							}
						}
					} else {
						forn(i, s.length()) {
							if (isdigit(s[i])) {
								s[i] = 'A';
								break;
							}
						}
					}
				} else {
					s[0] = '0';
					s[1] = 'A';
				}
    		}
    	} else {
    		if (b) {
    			if (c) {
    				if (b > 1) {
						forn(i, s.length()) {
							if (isupper(s[i])) {
								s[i] = 'a';
								break;
							}
						}
					} else {
						forn(i, s.length()) {
							if (isdigit(s[i])) {
								s[i] = 'a';
								break;
							}
						}
					}
    			} else {
    				s[0] = 'a';
    				s[1] = '0';
    			}
    		} else {
    			if (c) {
    				s[0] = 'a';
    				s[1] = 'A';
				} else {
					return 1;
				}
    		}
    	}
    	cout << s << "\n";
    }
    return 0;
}
