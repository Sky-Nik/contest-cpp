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
    os << v.size() << "\n";
    for (const auto& e: v) {
        os << e << " ";
    }
    os << "\n";
    return os;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> p1(2), p2(2);
    cin >> p1 >> p2;
    bool k1 = p1[0][0] == 'A' && p1[0][1] == 'B' && p1[1][1] == 'C' ||
        p1[0][1] == 'A' && p1[1][1] == 'B' && p1[1][0] == 'C' ||
        p1[1][1] == 'A' && p1[1][0] == 'B' && p1[0][0] == 'C' ||
        p1[1][0] == 'A' && p1[0][0] == 'B' && p1[0][1] == 'C' ||
        p1[0][0] == 'A' && p1[0][1] == 'B' && p1[1][0] == 'C' ||
        p1[0][1] == 'A' && p1[1][1] == 'B' && p1[0][0] == 'C' ||
        p1[1][1] == 'A' && p1[1][0] == 'B' && p1[0][1] == 'C' ||
        p1[1][0] == 'A' && p1[0][0] == 'B' && p1[1][1] == 'C' ||
        p1[0][0] == 'A' && p1[1][1] == 'B' && p1[1][0] == 'C' ||
        p1[0][1] == 'A' && p1[1][0] == 'B' && p1[0][0] == 'C' ||
        p1[1][1] == 'A' && p1[0][0] == 'B' && p1[0][1] == 'C' ||
        p1[1][0] == 'A' && p1[0][1] == 'B' && p1[1][1] == 'C';
    bool k2 = p2[0][0] == 'A' && p2[0][1] == 'B' && p2[1][1] == 'C' ||
        p2[0][1] == 'A' && p2[1][1] == 'B' && p2[1][0] == 'C' ||
        p2[1][1] == 'A' && p2[1][0] == 'B' && p2[0][0] == 'C' ||
        p2[1][0] == 'A' && p2[0][0] == 'B' && p2[0][1] == 'C' ||
        p2[0][0] == 'A' && p2[0][1] == 'B' && p2[1][0] == 'C' ||
        p2[0][1] == 'A' && p2[1][1] == 'B' && p2[0][0] == 'C' ||
        p2[1][1] == 'A' && p2[1][0] == 'B' && p2[0][1] == 'C' ||
        p2[1][0] == 'A' && p2[0][0] == 'B' && p2[1][1] == 'C' ||
        p2[0][0] == 'A' && p2[1][1] == 'B' && p2[1][0] == 'C' ||
        p2[0][1] == 'A' && p2[1][0] == 'B' && p2[0][0] == 'C' ||
        p2[1][1] == 'A' && p2[0][0] == 'B' && p2[0][1] == 'C' ||
        p2[1][0] == 'A' && p2[0][1] == 'B' && p2[1][1] == 'C';
    if (k1 == k2) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
