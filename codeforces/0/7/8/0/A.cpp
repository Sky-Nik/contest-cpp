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
    int n;
    cin >> n;
    vector<int> x(n << 1);
    cin >> x;
    vector<int> cnt(n);
    int c = 0, m = 0;
    for (auto xi: x) {
        ++cnt[xi - 1];
        if (cnt[xi - 1] == 1) {
            ++c;
        } else {
            --c;
        }
        m = max(m, c);
    }
    cout << m;
    return 0;
}