#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
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
    vector<int> k(n);
    cin >> k;
    vector<vector<int>> m(n);
    ll a = numeric_limits<ll>::max();
    forn(i, n) {
        m[i].resize(k[i]);
        cin >> m[i];
        a = min(a, 15 * k[i] + 5 * sum(m[i]));
    }
    cout << a;
    return 0;
}