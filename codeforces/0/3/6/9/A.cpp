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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    cin >> a;
    int answer = 0;
    forn(i, n) {
    	if (a[i] == 1) {
    		if (m > 0) {
    			--m;
    		} else {
    			++answer;
    		}
    	} else {
    		if (k > 0) {
    			--k;
    		} elif (m > 0) {
    			--m;
    		} else {
    			++answer;
    		}
    	}
    }
    cout << answer;
    return 0;
}