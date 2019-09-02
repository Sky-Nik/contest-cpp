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
inline ostream& operator << (ostream& os, const vector<T>& v) {
    for (const auto& e: v) {
        cout << e << " ";
    }
    cout << "\n";
    return os;
}

template<typename U, typename V>
inline istream& operator >> (istream& is, pair<U, V>& p) {
    cin >> p.first >> p.second;
    return is;
}

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
    int n, ai, answer = 0;
    cin >> n;
    vector<int> f(5000, 0);
    forn(i, n) {
        cin >> ai;
        ++f[ai - 1];
    }
    forn(i, n) {
		answer += abs(f[i] - 1);
	}
    fore(i, n, 5000) {
		answer += abs(f[i] - 0);
	}
    cout << (answer >> 1);
    return 0;
}
