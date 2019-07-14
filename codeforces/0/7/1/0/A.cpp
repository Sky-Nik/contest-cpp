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
    char c;
    int d;
    cin >> c >> d;
    if ((c == 'a' || c == 'h') && (d == 1 || d == 8)) {
        cout << 3;
    } elif ((c == 'a' || c == 'h') || (d == 1 || d == 8)) {
        cout << 5;
    } else {
        cout << 8;
    }
    return 0;
}