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
    int n, k, i = 0;
    cin >> n >> k;
    vector<pii> a(n);
    forn(i, n) {
    	cin >> a[i].first;
    	a[i].second = i + 1;
    }
    sort(begin(a), end(a));
    while (i < n && k >= a[i].first) {
        k -= a[i].first;
    	++i;
    }
    cout << i << "\n";
    forn(j, i) cout << a[j].second << " ";
    return 0;
}