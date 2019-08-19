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
    int n, m;
    cin >> n >> m;
    map<string, string> d;
    forn(i, m) {
        string ai, bi;
        cin >> ai >> bi;
        d[ai] = bi;
    }
    forn(i, n) {
        string ci;
        cin >> ci;
        if (d[ci].length() < ci.length()) {
            cout << d[ci] << " ";
        } else {
            cout << ci << " ";
        }
    }
    return 0;
}