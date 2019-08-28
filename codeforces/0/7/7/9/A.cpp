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
    int n, answer = 0;
    cin >> n;
    vector<int> a(n), b(n), fa(5, 0), fb(5, 0);
    cin >> a >> b;
    forn(i, n) ++fa[a[i] - 1];
    forn(i, n) ++fb[b[i] - 1];
    bool np = false;
    forn(i, 5) {
    	np |= abs(fa[i] - fb[i]) & 1;
    	answer += abs(fa[i] - fb[i]) >> 1;
    }
    if (np || answer & 1) {
    	cout << -1;
    } else {
    	cout << (answer >> 1);
    }
    return 0;
}