#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
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
    cin >> s;
    set<string> w;
    forn (i, s.length() + 1) {
        forn (j, 26) {
            t = s.substr(0, i) + static_cast<char>(j + 'a') + s.substr(i, s.length() - i);
            w.insert(t);
        }
    }
    cout << w.size();
    return 0;
}