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

const int MAXK = 100100;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> aa(n, 0);
    cin >> aa;
    set<int> sa;
    forn(i, n) {
        sa.insert(aa[i]);
    }
    vector<int> a(1, 0);
    for (const auto& sai: sa) {
        a.push_back(sai);
    }
    sort(begin(a), end(a));
    vector<int> d(MAXK, 0);
    forn(i, size(a) - 1) {
        d[i] = a[i + 1] - a[i];
    }
    forn(i, k) {
        cout << d[i] << "\n";
    }
    return 0;
}