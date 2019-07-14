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
    vector<int> c(n);
    cin >> c;
    int l = 0, r = n - 1;
    while (c[l] == c[n - 1]) {
        ++l;
    }
    //cout << "l = " << l << "\n";
    while (c[0] == c[r]) {
        --r;
    }
    //cout << "r = " << r << "\n";
    cout << max(r, n - 1 - l);
    return 0;
}