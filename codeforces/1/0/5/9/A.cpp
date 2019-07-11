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
    int n, L, a;
    cin >> n >> L >> a;
    vector<int> t(n + 2), l(n + 2);
    t[0] = 0; l[0] = 0;
    t[n + 1] = L; l[n + 1] = 0;
    forn(i, n) {
        cin >> t[i + 1] >> l[i + 1];
    }
    int ans = 0;
    forn(i, n + 1) {
        ans += (t[i + 1] - (t[i] + l[i])) / a;
    }
    cout << ans;
    return 0;
}