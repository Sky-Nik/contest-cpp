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
    string s, t, w;
    cin >> s >> t;
    cout << s << " " << t << "\n";
    int n;
    cin >> n;
    forn(i, n) {
        cin >> w;
        if (w == s) {
            cin >> s;
        } else {
            cin >> t;
        }
        cout << s << " " << t << "\n";
    }
    return 0;
}