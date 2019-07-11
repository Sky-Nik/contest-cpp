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
    int n;
    cin >> n;
    vector<int> t(n + 1);
    t[0] = 0;
    forn(i, n) {
        cin >> t[i + 1];
    }
    int c = 0;
    forn(i, n) {
        if (t[i + 1] - t[i] <= 15) {
            c = t[i + 1];
        } else {
            cout << c + 15;
            return 0;
        }
    }
    cout << min(90, c + 15);
    return 0;
}