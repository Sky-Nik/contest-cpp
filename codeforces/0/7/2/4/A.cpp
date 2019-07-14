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
    string s, t;
    cin >> s >> t;
    map<string, int> mp{
        {"monday", 1},
        {"tuesday", 2},
        {"wednesday", 3},
        {"thursday", 4},
        {"friday", 5},
        {"saturday", 6},
        {"sunday", 7},
    };
    set<int> ss{28 % 7, 30 % 7, 31 % 7};
    if (ss.find(mp[t] - mp[s]) != end(ss) ||
        ss.find(7 + mp[t] - mp[s]) != end(ss)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}