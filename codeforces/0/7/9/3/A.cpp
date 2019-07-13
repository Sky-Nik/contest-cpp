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
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;
    auto m = *min_element(begin(a), end(a));
    //cout << "m = " << m << "\n";
    ll ans = 0;
    bool possible = true;
    forn(i, n) {
        if ((a[i] - m) % k == 0) {
            ans += (a[i] - m) / k;
        } else {
            possible = false;
        }
    }
    if (possible) {
        cout << ans;
    } else {
        cout << -1;
    }
    return 0;
}