#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
#define sort(v) sort(begin(v), end(v))
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
    int n, t, p = 0;
    cin >> n >> t;
    vector<int> a(n);
    cin >> a;
    forn(i, n) {
        p += 86400 - a[i];
        if (p >= t) {
            cout << i + 1;
            return 0;
        }
    }
}
