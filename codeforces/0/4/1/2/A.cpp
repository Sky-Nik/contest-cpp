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
inline istream& operator >> (istream& is, vector<T>& v) {
    for (auto& e: v) {
        cin >> e;
    }
    return is;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<bool> p(n, false); 
    string s;
    cin >> s;
    if (k > (n >> 1)) {
    	while (k <= n) {
    		if (!p[k - 1]) {
    			cout << "PRINT " << s[k - 1] << "\n"; 
    			p[k - 1] = true;
    		}
    		if (k < n) {
    			cout << "RIGHT\n";
    			++k;
    		} else {
    			break;
    		}
    	} 
    	while (k > 1 && p[k - 1]) {
    		cout << "LEFT\n";
    		--k;
    	} 
    	while (k > 0) {
    		if (!p[k - 1]) {
	    		cout << "PRINT " << s[k - 1] << "\n";
    			p[k - 1] = true;
	    	}
    		if (k > 1) {
    			cout << "LEFT\n";
    			--k;
    		} else {
    			break;
    		}
    	}
    } else { 
    	while (k > 0) {
    		if (!p[k - 1]) {
	    		cout << "PRINT " << s[k - 1] << "\n"; 
    			p[k - 1] = true;
    		}
    		if (k > 1) {
    			cout << "LEFT\n";
    			--k;
    		} else {
    			break;
    		}
    	}
    	while (k < n && p[k - 1]) {
    		cout << "RIGHT\n";
    		++k;
    	}
		while (k <= n) {
    		if (!p[k - 1]) {
	    		cout << "PRINT " << s[k - 1] << "\n"; 
    			p[k - 1] = true;
    		}
    		if (k < n) {
    			cout << "RIGHT\n";
    			++k;
    		} else {
    			break;
    		}
    	} 
    }
    return 0;
}