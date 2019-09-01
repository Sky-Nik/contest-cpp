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

inline ostream& operator << (ostream& os, const vector<int>& v) {
    for (const auto& e: v) {
        cout << e << " ";
    }
    cout << "\n";
    return os;
}

inline ostream& operator << (ostream& os, const vector<vector<int>>& v) {
    for (const auto& e: v) {
        cout << e;
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
    vector<vector<int>> a(3, vector<int> (3, 0));
    forn(i, 3) forn(j, 3) cin >> a[i][j];
    vector<int> s(3);
    forn(i, 3) s[i] = sum(a[i]);
    int m = *max_element(begin(s), end(s));
    forn(i, 3) a[i][i] = m + 1 - s[i];
    int sd1 = a[0][0] + a[1][1] + a[2][2], sd2 = a[0][2] + a[1][1] + a[2][0];
    forn(i, 3) a[i][i] += (sd2 - sd1) >> 1;
    cout << a;
    return 0;
}
