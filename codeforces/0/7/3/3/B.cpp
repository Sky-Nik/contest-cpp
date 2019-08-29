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
    vector<int> l(n), r(n);
    forn(i, n) cin >> l[i] >> r[i];
    int sl = sum(l), sr = sum(r);
    int answer = abs(sl - sr), k = -1;
    forn(i, n) {
    	int current = abs((sl - l[i] + r[i]) - (sr - r[i] + l[i]));
    	if (current > answer) {
    		k = i;
    		answer = current;
    	}
    }
    cout << k + 1;
    return 0;
}