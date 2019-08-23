#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, l, r) for(int i = l; i < r; ++i)
#define sum(a) accumulate(begin(a), end(a), 0ll)

template<typename T>
inline ostream& operator << (ostream& os, const vector<T>& v) {
    for (const auto& e: v) {
        cout << e; // problem-specific
    }
    cout << "\n";
    return os;
}

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
    int s, t;
    vector<char> sc(5), tc(5);
    cin >> sc >> tc;
    s = 600 * (sc[0] - '0') + 60 * (sc[1] - '0') + 10 * (sc[3] - '0') + (sc[4] - '0');
    t = 600 * (tc[0] - '0') + 60 * (tc[1] - '0') + 10 * (tc[3] - '0') + (tc[4] - '0');
    int p = (s - t + 1440) % 1440;
    vector<char> pc(5);
    pc[0] = '0' + p / 600;
    p %= 600;
    pc[1] = '0' + p / 60;
    p %= 60;
    pc[2] = ':';
    pc[3] = '0' + p / 10;
    p %= 10;
    pc[4] = '0' + p;
    cout << pc;
    return 0;
}