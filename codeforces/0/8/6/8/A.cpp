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
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> w(n);
    cin >> w;
    bool possible = false;
    forn(i, n) {
        if (w[i][0] == s[0] && w[i][1] == s[1]) {
            possible = true;
        }
        forn(j, n) {
            if (w[i][1] == s[0] && w[j][0] == s[1]) {
                possible = true;
            }
        }
    }
    if (possible) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}