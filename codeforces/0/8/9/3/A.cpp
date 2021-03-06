#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
#define sort(v) sort(begin(v), end(v))

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
    int n, c = 3, w = -1;
    cin >> n;
    bool possible = true;
    forn(i, n) {
        cin >> w;
        if (c == w) {
            possible = false;
        }
        c = (6 - c - w);
    }
    if (possible) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
