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
    int t;
    string x, y;
    cin >> t;
    while (t --> 0) {
    	cin >> x >> y;
    	auto py = find(rbegin(y), rend(y), '1');
    	auto dy = distance(rbegin(y), py);
    	auto rx = rbegin(x);
    	advance(rx, dy);
    	auto px = find(rx, rend(x), '1');
    	auto dx = distance(rx, px);
    	cout << dx << "\n";
    }
    return 0;
}