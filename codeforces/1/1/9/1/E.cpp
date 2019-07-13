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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    // 1 = black, 0 = white
    ll first_white = -1, first_black = -1, last_white = -1, last_black = -1;
    forn(i, n) {
        if (first_black == -1 && s[i] == '1') {
            first_black = i;
        }
        if (first_white == -1 && s[i] == '0') {
            first_white = i;
        }
        if (s[i] == '1') {
            last_black = i;
        } else {
            last_white = i;
        }
    }
    if (last_white - first_white < k || last_black - first_black < k) {
        cout << "tokitsukaze";
    } elif (last_white - first_white > k || last_black - first_black > k) {
        cout << "once again";
    } else {
        if (k + 1 == (n >> 1)) {
            cout << "once again";
        } else {
            cout << "quailty";
        }
    }
    return 0;
}