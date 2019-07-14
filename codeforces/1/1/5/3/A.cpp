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
    int n, t;
    cin >> n >> t;
    int a = -1, m = numeric_limits<int>::max();
    forn(i, n) {
        int si, di;
        cin >> si >> di;
        int ti = max(si, t + ((si - t) % di + di) % di);
        if (ti < m) {
            m = ti;
            a = i + 1;
        }
    }
    cout << a;
    return 0;
}