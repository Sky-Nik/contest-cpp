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
    vector<int> m(5), w(5), p(5); int h_s, h_u;
    cin >> m >> w >> h_s >> h_u;
    forn(i, 5) p[i] = max(150 * (i + 1), (500 - 2 * m[i]) * (i + 1) - 50 * w[i]);
    cout << sum(p) + 100 * h_s - 50 * h_u;
    return 0;
}