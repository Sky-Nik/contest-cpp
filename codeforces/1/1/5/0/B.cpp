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
    vector<string> b(n);
    cin >> b;
    fore(i, 1, n - 1) {
        fore(j, 1, n - 1) {
            if (b[i][j] == '.' && b[i][j - 1] == '.' && b[i][j + 1] == '.' &&
                b[i - 1][j] == '.' && b[i + 1][j] == '.') {
                b[i][j] = '#';
                b[i][j - 1] = '#';
                b[i][j + 1] = '#';
                b[i - 1][j] = '#';
                b[i + 1][j] = '#';
            }
        }
    }
    bool possible = true;
    forn(i, n) {
        forn(j, n) {
            if (b[i][j] == '.') {
                possible = false;
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