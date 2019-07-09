#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
#define sort(v) sort(begin(v), end(v))

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
    int o = 0, t = 0;
    forn(i, n) {
        if (a[i] == 1) {
            ++o;
        } else {
            ++t;
        }
    }
    int m = min(o, t);
    cout << m + (o - m) / 3;
    return 0;
}
