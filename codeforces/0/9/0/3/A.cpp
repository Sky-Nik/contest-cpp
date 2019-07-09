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
    int n, x;
    cin >> n;
    forn(i, n) {
        cin >> x;
        if (x % 3 == 0 || x % 7 == 0 || x == 10 || x >= 12) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
