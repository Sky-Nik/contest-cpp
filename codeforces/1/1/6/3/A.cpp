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
    int n, m;
    cin >> n >> m;
    if (m == 0 || m == 1) {
        cout << 1;
    } else {
        vector<bool> cats(n, true);
        int j = 0;
        forn(i, m) {
            cats[j] = false;
            j += 2;
            j %= n;
            if (j == 0) {
                ++j;   
            }
        }
        cats.push_back(cats[0]);
        int a = 0;
        forn(i, n) {
            if (cats[i] != cats[i + 1]) {
                ++a;
            }
        }
        cout << (a >> 1); 
    }
    return 0;
}