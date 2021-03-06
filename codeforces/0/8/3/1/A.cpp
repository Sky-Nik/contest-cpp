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
    int n, s = 1;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    a.push_back(0);
    bool p = true;
    forn(i, n) {
    	if (s == 1) {
    		if (a[i + 1] > a[i]) {
    			s = 1;
    		} elif (a[i + 1] == a[i]) {
    			s = 0;
    		} elif (a[i + 1] < a[i]) {
    			s = -1;
    		}
    	} elif (s == 0) {
    		if (a[i + 1] > a[i]) {
    			p = false;
    		} elif (a[i + 1] == a[i]) {
    			s = 0;
    		} elif (a[i + 1] < a[i]) {
    			s = -1;
    		}
    	} elif (s == -1) {
    		if (a[i + 1] > a[i]) {
    			p = false;
    		} elif (a[i + 1] == a[i]) {
    			p = false;
    		} elif (a[i + 1] < a[i]) {
    			s = -1;
    		}
    	}
    }
    if (p) {
    	cout << "YES";
    } else {
    	cout << "NO";
    }
    return 0;
}