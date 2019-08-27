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
    vector<int> a(6);
    cin >> a;
    int s = sum(a);
    bool possible = false;
    forn(i, 6) fore(j, i + 1, 6) fore(k, j + 1, 6) possible |= ((a[i] + a[j] + a[k]) << 1 == s);
    if (possible) {
    	cout << "YES";
    } else {
    	cout << "NO";
    }
    return 0;
}