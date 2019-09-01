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
    int x, y, ax, ay, x1, y1, x2, y2;
    cin >> x >> y;
    tie(ax, ay) = make_pair(abs(x), abs(y));
    if (x < 0) {
    	if(y < 0) {
    		tie(x1, y1, x2, y2) = make_tuple(-ax - ay, 0, 0, -ax - ay);
    	} else {
    		tie(x1, y1, x2, y2) = make_tuple(-ax - ay, 0, 0, ax + ay);
    	}
    }  else {
    	if(y < 0) {
    		tie(x1, y1, x2, y2) = make_tuple(0, -ax - ay, ax + ay, 0);
    	} else {
    		tie(x1, y1, x2, y2) = make_tuple(0, ax + ay, ax + ay, 0);
    	}
    }
	cout << x1 << " " << y1 << " " << x2 << " " << y2;
    return 0;
}
