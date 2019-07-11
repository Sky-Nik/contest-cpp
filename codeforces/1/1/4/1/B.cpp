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
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    a.insert(end(a), begin(a), end(a));
    int c = 0, m = 0;
    forn(i, n << 1) {
        if (a[i]) {
            ++c;
        } else {
            m = max(m, c);
            c = 0;
        }
    } 
    cout << m;
    return 0;
}