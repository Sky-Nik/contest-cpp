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
        cin >> e;
    }
    return is;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, li, ri, pos, neg, d;
    cin >> n >> m;
    vector<int> a(n);
    cin >> a;
    pos = count(begin(a), end(a), 1);
    neg = count(begin(a), end(a), -1);
    while (m --> 0) {
        cin >> li >> ri;
        d = ri - li;
        if ((d & 1) && ((d + 1) >> 1) <= min(pos, neg)) {
        	cout << 1 << "\n";
        } else {
        	cout << 0 << "\n";
        }
    }
    return 0;
}
