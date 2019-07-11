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
    vector<vector<int>> stops(n);
    forn(i, n) {
        int ri;
        cin >> ri;
        stops[i].resize(ri);
        cin >> stops[i];
        sort(begin(stops[i]), end(stops[i]));
    }
    set<int> answer(begin(stops[0]), end(stops[0]));
    forn(i, n) {
        //cout << "| ";
        //for (const auto& e: stops[i]) {
        //    cout << e << " ";
        //}
        vector<int> tmp(size(answer));
        auto it_end = set_intersection(begin(answer), end(answer), begin(stops[i]), end(stops[i]), begin(tmp));
        answer = set<int>(begin(tmp), it_end);
        //cout << "| ";
        //for (const auto& e: answer) {
        //    cout << e << " ";
        //}
        //cout << "\n";
    }
    for (const auto& e: answer) {
        cout << e << " ";
    }
    return 0;
}