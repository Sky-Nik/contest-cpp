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
    int c = 0;
    forn(i, n) {
        int si, di;
        cin >> si >> di;
        if (c < si) {
            c = si;
        } else {
            if (c % di > si % di) {
                c += di - c % di;
            }
            c += si % di - c % di;
        }
        ++c;
    }
    cout << c - 1;
    return 0;
}