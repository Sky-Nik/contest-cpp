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
    int t, b, p, f, h, c;
    cin >> t;
    while (t --> 0) {
		cin >> b >> p >> f >> h >> c;
		cout << max(h * min(b >> 1, p) + c * max(0, min(b - (p << 1) >> 1, f)),
			c * min(b >> 1, f) + h * max(0, min(b - (f << 1) >> 1, p))) << "\n";
    }
    return 0;
}