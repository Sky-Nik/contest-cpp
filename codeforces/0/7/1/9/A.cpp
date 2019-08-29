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
    cin >> n;
    vector<int> a(n);
    cin >> a;
    if (n == 1) {
    	if (a[0] == 0) {
    		cout << "UP";
    	} elif (a[0] == 15) {
    		cout << "DOWN";
    	} else {
    		cout << -1;
    	}
    } else {
    	if (a[n - 1] == 0) {
    		cout << "UP";
    	} elif (a[n - 1] == 15) {
    		cout << "DOWN";
    	} else {
    		if (a[n - 2] < a[n - 1]) {
    			cout << "UP";
    		} else {
    			cout << "DOWN";
    		}
    	}
    }
    return 0;
}