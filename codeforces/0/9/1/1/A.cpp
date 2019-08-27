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
    int n, m, l = -1, r = -1, answer = numeric_limits<int>::max();
    cin >> n;
    vector<int> a(n);
    cin >> a;
    m = *min_element(begin(a), end(a));
    forn(i, n) if (a[i] == m) {
    	if (l == -1) {
    		l = i;
    	} elif (r == -1) {
    		r = i;
    	} else {
    		answer = min(answer, r - l);
    		tie(l, r) = make_pair(r, i);
    	}
    }
    cout << min(answer, r - l);
    return 0;
}