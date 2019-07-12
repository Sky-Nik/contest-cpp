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
    int n;
    cin >> n;
    int u = 0, d = 0, l = 0, r = 0;
    forn(i, n) {
        char c;
        cin >> c;
        if (c == 'U') {
            ++u;
        } elif (c == 'R') {
            ++r;
        } elif (c == 'D') {
            ++d;
        } else {
            ++l;
        }
    }
    cout << ((min(l, r) + min(u, d)) << 1);
    return 0;
}