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
    vector<int> d(n);
    cin >> d;
    int s, t;
    cin >> s >> t;
    ll l = sum(d), m = accumulate(begin(d) + min(s, t) - 1, begin(d) + max(s, t) - 1, 0ll);
    cout << min(m, l - m);
    return 0;
}