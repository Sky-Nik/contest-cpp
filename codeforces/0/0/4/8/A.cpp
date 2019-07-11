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

struct hand {
    int type;
    
    friend bool operator < (const hand& h1, const hand& h2) {
        return (h1.type == 1 && h2.type == 2) ||
            (h1.type == 2 && h2.type == 3) ||
            (h1.type == 3 && h2.type == 1);
    }
    
    friend bool operator > (const hand& h1, const hand& h2) {
        return h2 < h1;
    }
};


istream& operator >> (istream& is, hand& h) {
    string s;
    is >> s;
    if (s == "rock") {
        h.type = 1;
    } elif (s == "paper") {
        h.type = 2;
    } else {
        h.type = 3;
    }
    return is;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<hand, string>> fms(3);
    fms[0].second = "F"; fms[1].second = "M"; fms[2].second = "S";
    cin >> fms[0].first; cin >> fms[1].first; cin >> fms[2].first;
    if (fms[0].first > fms[1].first && fms[0].first > fms[2].first) {
        cout << fms[0].second;
    } elif (fms[1].first > fms[0].first && fms[1].first > fms[2].first) {
        cout << fms[1].second;
    } elif (fms[2].first > fms[0].first && fms[2].first > fms[1].first) {
        cout << fms[2].second;
    } else {
        cout << "?";
    }
    return 0;
}