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

ll score(vector<int> a, int i) {
	int k = a[i] / 14, l = a[i] % 14;
	a[i] = 0;
	forn(j, 14) {
		a[j] += k;
	}
	int j = (i + 1) % 14;
	forn(m, l) {
		++a[j];
		j = (j + 1) % 14;
	}
	ll answer = 0;
	forn(m, 14) {
		if (a[m] % 2 == 0) {
			answer += a[m];
		}
	}
	return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll answer = 0;
    vector<int> a(14);
    cin >> a;
    forn(i, 14) {
    	answer = max(answer, score(a, i));
    }
    cout << answer;
    return 0;
}
