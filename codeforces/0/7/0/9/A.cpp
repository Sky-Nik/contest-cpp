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
    int n, b, d;
    cin >> n >> b >> d;
    vector<int> a(n);
    cin >> a;
    int ans = 0, c = 0;
    forn(i, n) {
        if (a[i] <= b) {
            c += a[i];
            if (c > d) {
                ++ans;
                c = 0;
            }
        }
    }
    cout << ans;
    return 0;
}