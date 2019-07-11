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

template<typename T>
T min_(T t) {
    return t;
}

template<typename T, typename... Args>
T min_(T t, Args... args) {
    return min(t, min_(args...));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    cout << min_(k * l / nl, c * d, p / np) / n;
    return 0;
}