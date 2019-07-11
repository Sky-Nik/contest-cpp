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
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int m;
    cin >> m;
    forn(i, m) {
        int x, y;
        cin >> x >> y;
        --x;
        if (x > 0) {
            a[x - 1] += y - 1;
        }
        if (x + 1 < n) {
            a[x + 1] += a[x] - y;
        }
        a[x] = 0;
    }
    forn(i, n) {
        cout << a[i] << "\n";
    }
    return 0;
}