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

char next_cw(char c) { 
    if (c == '^') {
        return '>';
    } elif (c == '>') {
        return 'v';
    } elif (c == 'v') {
        return '<';
    } else {
        return '^';
    }
}

char next_ccw(char c) { 
    if (c == '^') {
        return '<';
    } elif (c == '<') {
        return 'v';
    } elif (c == 'v') {
        return '>';
    } else {
        return '^';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    char b, a;
    cin >> b >> a;
    int n;
    cin >> n;
    n %= 4;
    char cwb = b;
    forn(i, n) {
        cwb = next_cw(cwb);
    }
    bool cw = cwb == a;
    char ccwb = b;
    forn(i, n) {
        ccwb = next_ccw(ccwb);
    }
    bool ccw = ccwb == a;
    if (cw && ccw) {
        cout << "undefined";
    } elif (cw) {
        cout << "cw";
    } else {
        cout << "ccw";
    }
    return 0;
}