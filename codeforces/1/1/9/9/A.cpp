#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    cin >> a;
    forn(i, n) {
        bool k = true;
        fore(j, max(0, i - x), i) {
            k &= a[j] > a[i];
        }
        fore(j, i + 1, min(n, i + y + 1)) {
            k &= a[j] > a[i];
        }
        if (k) {
            cout << i + 1;
            return 0;
        }
    }
}