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
    int x;
    string s;
    cin >> x >> s >> s;
    if (s == "week") {
        if (x == 5 || x == 6) {
            cout << 53;
        } else {
            cout << 52;
        }
    } else {
        if (x <= 29) {
            cout << 12;
        } elif (x == 30) {
            cout << 11;
        } else {
            cout << 7;
        }
    }
    return 0;
}