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
    int n, m;
    cin >> n >> m;
    vector<pii> tx(n + m);
    forn(i, n + m) cin >> tx[i].second;
    forn(i, n + m) cin >> tx[i].first;
    sort(begin(tx), end(tx));
    tx.push_back({1, 2e9});
    int j = n;
    vector<int> answer(m, 0);
    forn(i, n) {
    	while (abs(tx[i].second - tx[j].second) > abs(tx[i].second - tx[j + 1].second)) {
    		++j;
    	}
    	++answer[j - n];
    }
    cout << answer;
    return 0;
}
