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
    string s, t = "heidi";
    cin >> s;
    int j = 0;
    forn(i, s.length()) {
        if (j < 5 && s[i] == t[j]) {
            ++j;
        }
    }
    if (j < 5) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    return 0;
}