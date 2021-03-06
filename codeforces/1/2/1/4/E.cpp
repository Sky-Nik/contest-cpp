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
    int n, di;
    cin >> n;
    vector<pii> d(n);
    vector<int> g;
    forn(i, n) {
        cin >> di;
        d[i] = {di, i};
    }
    sort(begin(d), end(d), greater<>());
    vector<vector<int>> answer(2 * n);
    forn(i, n - 1) {
        int j = d[i].second;
        int k = d[i + 1].second;
        answer[2 * j].push_back(2 * k);
        answer[2 * k].push_back(2 * j);
//        cout << 2 * j << "--" << 2 * k << " [1]\n"; // OK
    }
    g.push_back(d[n - 1].second);
    forn(i, n) {
        int u = d[i].second; // 2 * u + 1
        if (i + d[i].first > n - 1) {
            int j = i + d[i].first - (n - 1) - 1; // tc1 j = 1
//            cout << "j = " << j << "\n";
//            cout << "g.size() = " << g.size() << "\n";
            if (g.size() == 1) {
                int v = g[0];
//                cout << 2 * u + 1 << "--" << 2 * v << " [2]\n"; // Looks OK
                answer[2 * u + 1].push_back(2 * v);
                answer[2 * v].push_back(2 * u + 1);
                g.push_back(u);
            } else {
                if (j == 0) {
                    int v = g[0];
//                    cout << 2 * u + 1 << "--" << 2 * v << " [3]\n"; // Looks OK
                    answer[2 * u + 1].push_back(2 * v);
                    answer[2 * v].push_back(2 * u + 1);
                } else {
                    if (static_cast<int>(g.size()) > j + 1) {
                        int v = g[j];
//                        cout << 2 * u + 1 << "--" << 2 * v + 1 << " [4]\n"; // Looks OK
                        answer[2 * u + 1].push_back(2 * v + 1);
                        answer[2 * v + 1].push_back(2 * u + 1);
                    } else {
                        int v = g.back();
//                        cout << 2 * u + 1 << "--" << 2 * v + 1 << " [5]\n"; // Looks OK
                        answer[2 * u + 1].push_back(2 * v + 1);
                        answer[2 * v + 1].push_back(2 * u + 1);
                        g.push_back(u);
                    }
                }
            }
        } else {
            int j = i + d[i].first - 1;
            int v = d[j].second;
//            cout << 2 * u + 1 << "--" << 2 * v << " [6]\n"; // OK
            answer[2 * u + 1].push_back(2 * v);
            answer[2 * v].push_back(2 * u + 1);
        }
    }
    forn(i, 2 * n) for (int j : answer[i]) if (j > i) cout << i + 1 << " " << j + 1 << "\n";
    return 0;
}
