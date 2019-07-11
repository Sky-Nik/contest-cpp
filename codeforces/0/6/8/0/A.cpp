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
    map<int, int> t;
    int s = 0, ti, m = 0;
    forn(i, 5) {
        cin >> ti;
        if (t.find(ti) == t.end()) {
            t[ti] = 0;
        }
        ++t[ti];
        s += ti;
    }
    for (const auto& [ti, cnt]: t) {
        if (cnt == 2) {
            m = max(m, ti << 1);
        } elif (cnt >= 3) {
            m = max(m, 3 * ti);
        }
    }
    cout << s - m;
    return 0;
}