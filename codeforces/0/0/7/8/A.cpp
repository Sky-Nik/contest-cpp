#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

#define elif else if
#define forn(_i, _n) for(int _i = 0; _i < _n; ++_i)
#define fore(_i, _l, _r) for(int _i = _l; _i < _r; ++_i)
#define sum(a) accumulate(begin(a), end(a), 0ll)

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
    string s[3];
    forn(i, 3) getline(cin, s[i]);
    int c[3] = {5, 7, 5};
    char v[5] = {'a', 'e', 'i', 'o', 'u'};
    forn(i, 3) forn(j, s[i].length()) forn(k, 5) if (s[i][j] == v[k]) --c[i];
    bool p = true;
    forn(i, 3) p &= c[i] == 0;
    if (p) cout << "YES"; else cout << "NO";
    return 0;
}