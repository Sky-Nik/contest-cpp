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
inline ostream& operator << (ostream& os, const vector<T>& v) {
    for (const auto& e: v) {
        cout << e << " ";
    }
    cout << "\n";
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
    int n, k, j = 0;
    cin >> n >> k;
    vector<int> a(k);
    cin >> a;
    vector<bool> used(n * k, false);
    forn(i, k) used[a[i] - 1] = true;
    vector<vector<int>> parts(k);
    forn(i, k) parts[i].push_back(a[i]);
    forn(i, n * k) {
    	while (size(parts[j]) == n) ++j;
    	if (!used[i]) parts[j].push_back(i + 1);
    }
    cout << parts;
    return 0;
}