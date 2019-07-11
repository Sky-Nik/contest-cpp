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
    vector<ll> a(n);
    cin >> a;
    ll s = sum(a);
    int ans = 0;
    forn(i, n) {
        // cout << "s & 1 = " << (s & 1) << ", a[" << i << "] & 1 = " << (a[i] & 1) << "\n";
        if ((s & 1) == (a[i] & 1)) {
            ++ans;
        }
    }
    cout << ans;
    return 0;
}