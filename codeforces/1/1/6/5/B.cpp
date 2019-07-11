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

const int MAXN = 200100;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    sort(begin(a), end(a));
    int i = 0, k = 1;
    while (k <= n) {
        while (i < n && a[i] < k) {
            ++i;
        }
        if (i < n) {
            ++i;
            ++k;
        } else {
            break;
        }
    }
    cout << k - 1;
    return 0;
}