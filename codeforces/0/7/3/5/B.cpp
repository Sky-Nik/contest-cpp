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
    int n, n1, n2;
    ll answer1 = 0, answer2 = 0;
    cin >> n >> n1 >> n2;
    vector<int> a(n);
    cin >> a;
    sort(begin(a), end(a), greater<>());
    forn(i, min(n1, n2)) {
    	answer1 += a[i];
    }
    fore(i, min(n1, n2), n1 + n2) {
    	answer2 += a[i];
    }
    cout << fixed << setprecision(9) <<
    	static_cast<ld>(answer1) / min(n1, n2) +
		static_cast<ld>(answer2) / (n1 + n2 - min(n1, n2));
    return 0;
}
