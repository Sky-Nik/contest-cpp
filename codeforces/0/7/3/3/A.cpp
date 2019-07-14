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
    vector<int> p(1, 0);
    int n = s.length();
    forn(i, n) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
            s[i] == 'O' || s[i] == 'U' || s[i] == 'Y') {
            p.push_back(i + 1);
        }
    }
    p.push_back(n + 1);
    int M = 0;
    fore(i, 1, size(p)) {
        M = max(M, p[i] - p[i - 1]);
    }
    cout << M;
    return 0;
}