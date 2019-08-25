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
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool b1 = true;
    forn(i, n) if (s[i] != '4' && s[i] != '7') b1 = false;
    int s1h = 0, s2h = 0;
    forn(i, n >> 1) s1h += s[i] - '0';
    fore(i, n >> 1, n) s2h += s[i] - '0';
    if (b1 && s1h == s2h) cout << "YES";
    else cout << "NO";
    return 0;
}