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
    int n, k, answer = 0;
    cin >> n >> k;
    vector<pii> ab(n);
    forn(i, n) {
    	cin >> ab[i].first;
    }
    forn(i, n) {
    	cin >> ab[i].second;
    }
    sort(begin(ab), end(ab), [](const pii & a, const pii & b) -> bool {
    	return (a.first - a.second) < (b.first - b.second);
    });
    forn(i, k) {
    	answer += ab[i].first;
    }
    fore(i, k, n) {
    	answer += min(ab[i].first, ab[i].second);
    }
    cout << answer;
    return 0;
}
