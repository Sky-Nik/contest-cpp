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
    vector<int> a(n), b(n);
    cin >> a >> b;
    int i = 0;
    set<int> u;
    forn(j, n) {
        if (i == n) {
            cout << 0 << " ";
        } else {
            if (u.find(b[j]) == end(u)) {
                auto it = find(begin(a) + i, end(a), b[j]);
                int d = distance(begin(a) + i, it);
                //cout << "\nd = " << d << "\n";
                cout << d + 1 << " ";
                fore(k, i, i + d + 1) {
                    u.insert(a[k]);
                }
                i += d + 1;
            } else {
                cout << 0 << " ";
            }
        }
    }
    return 0;
}