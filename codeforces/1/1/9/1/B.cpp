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

bool shuntsu(const vector<string>& v) {
    forn(i, size(v)) {
        if (v[i][1] != v[0][1]) {
            return false;
        }
    }
    fore(i, 1, size(v)) {
        if (v[i - 1][0] + 1 != v[i][0]) {
            return false;
        }
    }
    return true;
}

bool shuntsu_(const vector<string>& v) {
    forn(i, size(v)) {
        if (v[i][1] != v[0][1]) {
            return false;
        }
    }
    fore(i, 1, size(v)) {
        if (v[i - 1][0] + 2 != v[i][0]) {
            return false;
        }
    }
    return true;
}

bool koutsu(const vector<string>& v) {
    forn(i, size(v)) {
        if (v[i] != v[0]) {
            return false;
        }
    }
    return true;
}

bool mentsu(const vector<string>& v) {
    return shuntsu(v) || koutsu(v);
}

bool mentsu_(const vector<string>& v) {
    return shuntsu_(v) || koutsu(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> s(3);
    cin >> s;
    sort(begin(s), end(s));
    vector<string> v01{s[0], s[1]}, v02{s[0], s[2]}, v12{s[1], s[2]};
    if (mentsu(s)) {
        cout << 0;
    } elif (mentsu(v01) || mentsu(v02) || mentsu(v12) ||
        mentsu_(v01) || mentsu_(v02) || mentsu_(v12)) {
        cout << 1;
    } else {
        cout << 2;
    }
    return 0;
}