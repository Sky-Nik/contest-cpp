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
    int k, r = 5, c = -1;
    cin >> k;
    for (; r * r <= k; ++r) {
        if (k % r == 0) {
            c = k / r;
            break;
        }
    }
    if (c == -1) {
        cout << -1;
    } else {
        vector<char> v{'a', 'e', 'i', 'o', 'u'};
        forn(i, r) {
            forn(j, c) {
                cout << v[(i + j) % 5];
            }
        }
    }
    return 0;
}