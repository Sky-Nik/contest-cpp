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

int next(int x, int n) {
	if (n & 1) {
		if (x == 0) {
			return 1;
		} elif (x == 1) {
			return 0;
		} else {
			return 2;
		}
	} else {
		if (x == 1) {
			return 2;
		} elif (x == 2) {
			return 1;
		} else {
			return 0;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    n %= 6;
    for (int i = n + 1; i --> 1;) x = next(x, i);
    cout << x;
    return 0;
}