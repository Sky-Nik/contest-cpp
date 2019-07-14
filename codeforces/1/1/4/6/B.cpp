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
    string t;
    cin >> t;
    int n = t.length();
    string ss;
    forn(i, n) {
        if (t[i] != 'a') {
            ss += t[i];
        }
    }
    int k = ss.length();
    if (k & 1) {
        cout << ":(";
        return 0;
    }
    k >>= 1;
    forn(i, k) {
        if (ss[i] != ss[k + i]) {
            cout << ":(";
            return 0;
        }
    }
    if (t.substr(n - k, k) != ss.substr(0, k)) {
        cout << ":(";
    } else {
        cout << t.substr(0, n - k);
    }
    return 0;
}