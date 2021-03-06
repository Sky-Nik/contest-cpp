#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> p(m + 1, 0);
    forn(i, m) {
        cin >> p[i + 1];
    }
    vector<pair<string, ll>> events((m << 1)|1);
    forn(i, m) {
        events[i << 1] = make_pair("usefull", p[i + 1] - p[i] - 1);
        events[(i << 1)|1] = make_pair("useless", 1);
    }
    events[m << 1] = make_pair("usefull", k);
    ll usefull = 0, useless = 0, answer = 0;
    for (const auto& [type, quantity]: events) {
        if (type == "usefull") {
            usefull += quantity;
        } else {
            ++useless;
        }
        if (usefull + useless >= k) {
            //cout << "usefull = " << usefull << ", useless = " << useless << "\n";
            if (useless) {
                ++answer;
                useless = 0;
            }
            usefull %= k;
        }
    }
    cout << answer;
    return 0;
}