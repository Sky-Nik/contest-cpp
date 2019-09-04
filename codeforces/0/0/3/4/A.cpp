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

template<typename U, typename V>
inline istream& operator >> (istream& is, pair<U, V>& p) {
    is >> p.first >> p.second;
    return is;
}

template<typename U, typename V>
inline ostream& operator << (ostream& os, pair<U, V>& p) {
    os <<  p.first << " " << p.second;
    os << "\n";
    return os;
}

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
    int n;
	cin >> n;
	vector<int> a(n), d(n);
	cin >> a;
	forn(i, n) d[i] = abs(a[(i + 1) % n] - a[i]);
	int p = distance(begin(d), min_element(begin(d), end(d)));
    cout << (p + 1) % n + 1 << " " << p + 1;
    return 0;
}
