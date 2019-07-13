#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, l, r) for(int i = l; i < r; ++i)
#define sum(a) accumulate(begin(a), end(a), 0)

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
    vector<vector<int>> b(7, vector<int>(n));
    forn(i, n) {
        forn(j, 7) {
            char c;
            cin >> c;
            if (c == '0') {
                b[j][i] = 0;
            } else {
                b[j][i] = 1;
            }
        }
    }
    vector<int> s(7);
    forn(i, 7) {
        s[i] = sum(b[i]);
    }
    auto max_el_it = max_element(begin(s), end(s));
    cout << (*max_el_it);
    return 0;
}