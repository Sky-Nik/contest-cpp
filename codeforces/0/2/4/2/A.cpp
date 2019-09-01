#include <bits/stdc++.h>
using namespace std;

//typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
//typedef pair<ll, int> pli;
//typedef pair<int, ll> pil;
//typedef pair<ll, ll> pll;

#define elif else if
#define forn(_i, _n) for(int _i = 0; _i < static_cast<int>(_n); ++_i)
#define fore(_i, _l, _r) for(int _i = _l; _i < _r; ++_i)
#define sum(a) accumulate(begin(a), end(a), 0ll)

inline ostream& operator << (ostream& os, const pii & p) {
    cout << p.first << " "  << p.second;
    return os;
}

// problem-specific
template<typename T>
inline ostream& operator << (ostream& os, const vector<T>& v) {
    cout << v.size() << "\n";
    for (const auto& e: v) {
        cout << e << "\n";
    }
    return os;
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
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    vector<pii> answer;
    fore(ci, a, x + 1) fore(di, b, y + 1) if (ci > di) answer.push_back(make_pair(ci, di));
    cout << answer;
    return 0;
}
