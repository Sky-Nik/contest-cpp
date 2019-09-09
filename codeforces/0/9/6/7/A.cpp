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
    int n, s, h, m;
	cin >> n >> s;
    vector<int> hm(n);
    forn(i, n) {
    	cin >> h >> m;
    	hm[i] = 60 * h + m;
    }
    hm.push_back(100500);
    if (hm[0] >= s + 1) {
    	cout << "0 0";
		return 0;
    } else {
		forn(i, n) {
			if (hm[i + 1] - hm[i] > 2 * s + 1) {
				int answer = hm[i] + s + 1;
				cout << answer / 60 << " " << answer % 60;
				return 0;
			}
		}
    }
}
