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
    int q, n;
    bool a, b;
    cin >> q;
    while (q --> 0) {
        cin >> n;
        vector<int> p(n);
        cin >> p;
        a = true;
        b = true;
        fore(i, 1, n) a &= ((n + p[i] - p[i - 1]) % n == 1);
        fore(i, 1, n) b &= ((n + p[i - 1] - p[i]) % n == 1);
        if (a || b) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}