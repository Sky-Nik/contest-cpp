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
    int r, c;
    cin >> r >> c;
    vector<string> b(r);
    forn(i, r) {
        cin >> b[i];
    }
    bool possible = true;
    fore(i, 1, r) {
        forn(j, c) {
            if (b[i - 1][j] == 'S' && b[i][j] == 'W' ||
                b[i - 1][j] == 'W' && b[i][j] == 'S') {
                possible = false;
            }
        }
    }
    forn(i, r) {
        fore(j, 1, c) {
            if (b[i][j - 1] == 'S' && b[i][j] == 'W' ||
                b[i][j - 1] == 'W' && b[i][j] == 'S') {
                possible = false;
            }
        }
    }
    if (possible) {
        cout << "YES\n";
        fore(i, 1, r) {
            forn(j, c) {
                if (b[i - 1][j] == 'S' && b[i][j] == '.') {
                    b[i][j] = 'D';
                }
                if (b[i][j] == 'S' && b[i - 1][j] == '.') {
                    b[i - 1][j] = 'D';
                }
            }
        }
        forn(i, r) {
            fore(j, 1, c) {
                if (b[i][j - 1] == 'S' && b[i][j] == '.') {
                    b[i][j] = 'D';
                }
                if (b[i][j] == 'S' && b[i][j - 1] == '.') {
                    b[i][j - 1] = 'D';
                }
            }
        }
        forn(i, r) {
            cout << b[i] << "\n";
        }
    } else {
        cout << "NO";
    }
    return 0;
}