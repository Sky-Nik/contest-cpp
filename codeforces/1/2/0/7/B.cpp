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
inline ostream& operator << (ostream& os, const pair<U, V>& p) {
    os <<  p.first << " " << p.second;
    // os << "\n";  // problem-specific
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
    os << v.size() << "\n"; // problem-specific
    for (const auto& e: v) {
        os << e << "\n"; // problem-specific
    }
    // os << "\n"; // problem-specific
    return os;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m, 0));
    cin >> a;
    vector<pii> answer;
    forn(i, n - 1) forn(j, m - 1) if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1]) {
    	answer.push_back({i + 1, j + 1});
    	b[i][j] = 1;
    	b[i + 1][j] = 1;
    	b[i][j + 1] = 1;
    	b[i + 1][j + 1] = 1;
    }
    bool p = true;
    forn(i, n) forn(j, m) p &= a[i][j] == b[i][j];
    if (p) {
    	cout << answer;
    } else {
    	cout << -1;
    }
    return 0;
}
