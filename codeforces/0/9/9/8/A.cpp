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
    vector<pair<int, int>> a(n);
    forn(i, n) {
        int ai;
        cin >> ai;
        a[i] = make_pair(ai, i);
    }
    sort(begin(a), end(a));
    if (n == 1) {
        cout << -1;
    } elif (n == 2 && a[0].first == a[1].first) {
        cout << -1;
    } else {
        cout << 1 << " " << a[0].second + 1;
    }
    return 0;
}