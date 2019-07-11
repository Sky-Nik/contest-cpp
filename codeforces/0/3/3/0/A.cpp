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
    int r, c;
    cin >> r >> c;
    vector<string> cake(r);
    forn(i, r) {
        cin >> cake[i];
    }
    int ra = 0, ca = 0;
    forn(i, r) {
        bool inc_ra = true;
        forn(j, c) {
            if (cake[i][j] == 'S') {
                inc_ra = false;
            }
        }
        if (inc_ra) {
            ++ra;
        }
    }
    forn(j, c) {
        bool inc_ca = true;
        forn(i, r) {
            if (cake[i][j] == 'S') {
                inc_ca = false;
            }
        }
        if (inc_ca) {
            ++ca;
        }
    }
    cout << r * c - (r - ra) * (c - ca);
    return 0;
}