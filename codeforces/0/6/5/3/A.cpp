#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, l, r) for(int i = l; i < r; ++i)
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
    int n, ti;
    cin >> n;
    vector<int> f(1010, 0);
    forn(i, n) {
    	cin >> ti;
    	++f[ti];
    }
    bool p = false;
    fore(i, 1, 1000) p |= (f[i - 1] && f[i] && f[i + 1]);
    if (p) cout << "YES"; else cout << "NO"; 
    return 0;
}