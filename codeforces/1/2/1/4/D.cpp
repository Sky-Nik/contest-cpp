#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

#define elif else if
#define forn(_i, _n) for(int _i = 0; _i < static_cast<int>(_n); ++_i)
#define fore(_i, _l, _r) for(int _i = _l; _i < _r; ++_i)
#define sum(a) accumulate(begin(a), end(a), 0ll)

template<typename T>
inline istream& operator >> (istream& is, vector<T>& v) {
    for (auto& e: v) {
        is >> e;
    }
    return is;
}

template<typename T>
inline ostream& operator << (ostream& os, const vector<T>& v) {
    for (const auto& e: v) {
        os << e << " ";
    }
    os << "\n";
    return os;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> island(n);
    cin >> island;
    for (int s = (n - 1) + (m - 1) - 1; s > 0; --s) {
        for (int i = max(0, s - (m - 1)); i <= min(s, n - 1); ++i) {
            int j = s - i;
            bool p = false;
            if (i + 1 < n) {
                p |= island[i + 1][j] == '.';
            }
            if (j + 1 < m) {
                p |= island[i][j + 1] == '.';
            }
            if (!p) {
                island[i][j] = '#';
            }
        }
    }
    vector<vector<int>> c(n, vector<int> (m, 0));
    c[0][0] = 1;
    for (int s = 0; s < (n - 1) + (m - 1); ++s) {
        for (int i = max(0, s - (m - 1)); i <= min(s, n - 1); ++i) {
//            cout << "s = " << s << " i = " << i << "\n";
            int j = s - i;
            if (c[i][j]) {
                if (i + 1 < n && island[i + 1][j] == '.') c[i + 1][j] = 1;
                if (j + 1 < m && island[i][j + 1] == '.') c[i][j + 1] = 1;
            }
        }
//        cout << c;
    }
    if (c[n - 1][m - 1] == 0.) {
        cout << 0;
    } else {
        bool one = false;
        for (int s = 1; s < (n - 1) + (m - 1); ++s) {
            int k = 0;
            for (int i = max(0, s - (m - 1)); i <= min(s, n - 1); ++i) {
                int j = s - i;
                k += c[i][j];
            }
            one |= k == 1;
//          cout << c;
        }
        if (one) {
            cout << 1;
        } else {
            cout << 2;
        }
    }
//    cout << "\n" << island;
    return 0;
}
