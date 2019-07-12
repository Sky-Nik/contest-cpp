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
    string s;
    cin >> s;
    int x = 0, y = 0;
    vector<int> c(n + 1, 0);
    forn(i, n) {
        if (s[i] == 'U') {
            ++x;
        } else {
            ++y;
        }
        c[i + 1] = ((x > y) ? -1 : (x < y ? 1 : 0));
    }
    int a = 0;
    fore(i, 1, n) {
        if (c[i - 1] * c[i + 1] == -1) {
            ++a;
        }
    }
    cout << a;
    return 0;
}