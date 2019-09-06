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
        is >> e;
    }
    return is;
}

template<typename T>
inline ostream& operator << (ostream& os, const vector<T>& v) {
    for (const auto& e: v) {
        os << e << " ";
    }
     os << "\n";
    return os;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q, n, k, c, j, i;
    cin >> q;
    while (q --> 0) {
		cin >> n >> k;
		vector<int> a(n), r(k, -1);
		cin >> a;
		if ((sum(a) & 1) == (k & 1)) {
			c = 0, j = 0, i = 0;
			while (i < k && j < n && !(c & 1)) {
				c = (c + a[j++]) & 1;
				if (c & 1) {
					c = 0;
					r[i++] = j;
				}
			}
			if (r[k - 1] == -1) {
				cout << "NO\n";
			} else {
				r[k - 1] = n;
				cout << "YES\n";
				cout << r;
			}
		} else {
			cout << "NO\n";
		}
    }
    return 0;
}
