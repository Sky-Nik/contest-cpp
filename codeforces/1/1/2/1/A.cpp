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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> p(n), s(n), c(k);
    cin >> p >> s >> c;
    set<int> sc(begin(c), end(c));
    map<int, int> mp;
    forn(i, n) {
        if (mp.find(s[i]) == end(mp)) {
            mp[s[i]] = 0;
        }
        mp[s[i]] = max(mp[s[i]], p[i]);
    }
    int a = 0;
    forn(i, n) {
        if (sc.find(i + 1) != end(sc) && mp[s[i]] != p[i]) {
            ++a;
        }
    }
    cout << a;
    return 0;
}