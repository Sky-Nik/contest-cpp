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
    vector<int> t(n);
    cin >> t;
    bool progression = true;
    forn(i, n) {
        if (t[i] - t[0] != i * (t[1] - t[0])) {
            progression = false;
        }
    }
    if (progression) {
        cout << t[0] + n * (t[1] - t[0]);
    } else {
        cout << t[n - 1];
    }
    return 0;
}