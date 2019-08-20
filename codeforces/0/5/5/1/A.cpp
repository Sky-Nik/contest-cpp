#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, l, r) for(int i = l; i < r; ++i)
#define sum(a) accumulate(begin(a), end(a), 0ll)

template<typename T>
inline ostream& operator << (ostream& os, const vector<T>& v) {
    for (const auto& e: v) {
        cout << e << " ";
    }
    cout << "\n";
    return os;
}

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
    vector<pii> a(n);
    forn(i, n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(begin(a), end(a), greater<>());
    vector<int> answer(n);
    int r = 0, c = -1;
    forn(i, n) {
        if (a[i].first != c) {
            c = a[i].first;
            r = i;
        }
        answer[a[i].second] = r + 1;
    }
    cout << answer;
    return 0;
}