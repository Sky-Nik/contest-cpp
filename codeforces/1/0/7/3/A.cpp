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
    string s;
    cin >> s;
    int diverse_idx = -1;
    forn(i, n - 1) {
        if (s[i] != s[i + 1]) {
            diverse_idx = i;
            //cout << "diverse_idx = " << diverse_idx << "\n";
        }
    }
    if (diverse_idx != -1) {
        cout << "YES\n" << s.substr(diverse_idx, 2);
    } else {
        cout << "NO";
    }
    return 0;
}