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
    vector<pii> lr1(n);
    cin >> lr1;
    int m;
    cin >> m;
    vector<pii> lr2(m);
    cin >> lr2;
    sort(begin(lr1), end(lr1), [](const pii & a, const pii & b) -> bool { return a.second < b.second; } );
    sort(begin(lr2), end(lr2), [](const pii & a, const pii & b) -> bool { return a.first < b.first; } );
    int answer = max(0, lr2[m - 1].first - lr1[0].second);
    sort(begin(lr1), end(lr1), [](const pii & a, const pii & b) -> bool { return a.first < b.first; } );
    sort(begin(lr2), end(lr2), [](const pii & a, const pii & b) -> bool { return a.second < b.second; } );
    answer = max(answer, lr1[n - 1].first - lr2[0].second);
    cout << answer;
    return 0;
}
