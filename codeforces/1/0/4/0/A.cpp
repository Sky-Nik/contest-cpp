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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> c(n);
    cin >> c;
    int ans = 0;
    bool possible = true;
    forn(i, n >> 1) {
        if (c[i] == 0) {
            if (c[n - 1 - i] == 1) {
                possible = false;
            } elif (c[n - 1 - i] == 2) {
                ans += a;
            } 
        } elif (c[i] == 1) {
            if (c[n - 1 - i] == 0) {
                possible = false;
            } elif (c[n - 1 - i] == 2) {
                ans += b;
            } 
        } else {
            if (c[n - 1 - i] == 0) {
                ans += a;
            } elif (c[n - 1 - i] == 1) {
                ans += b;
            } else {
                ans += min(a, b) << 1;
            }
        }
    }
    if (n & 1) {
        if (c[n >> 1] == 2) {
            ans += min(a, b);
        }
    }
    if (possible) {
        cout << ans;
    } else {
        cout << -1;
    }
    return 0;
}