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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int g = s.find('G'), t = s.find('T');
    bool possible = true;
    while (g > t) {
        if (g - k >= 0 && s[g - k] != '#') {
            g -= k;
        } else {
            possible = false;
            break;
        }
    }
    while (g < t) {
        if (g + k < n && s[g + k] != '#') {
            g += k;
        } else {
            possible = false;
            break;
        }
    }
    if (g == t) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}