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
    int a = 0;
    if (m % n) {
        cout << -1;
    } else {
        int d = m / n;
        while (d % 2 == 0) {
            ++a;
            d /= 2;
        }
        while (d % 3 == 0) {
            ++a;
            d /= 3;
        }
        if (d != 1) {
            cout << -1;
        } else {
            cout << a;
        }
    }
    return 0;
}