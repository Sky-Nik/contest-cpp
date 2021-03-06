#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

#define elif else if
#define forn(_i, _n) for(int _i = 0; _i < _n; ++_i)
#define fore(_i, _l, _r) for(int _i = _l; _i < _r; ++_i)
#define sum(a) accumulate(begin(a), end(a), 0ll)

template<typename T>
inline istream& operator >> (istream& is, vector<T>& v) {
    for (auto& e: v) {
        cin >> e;
    }
    return is;
}

template<typename T>
T max_(T t) {
    return t;
}

template<typename T, typename... Args>
T max_(T t, Args... args) {
    return max(t, max_(args...));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, g, b;
    cin >> r >> g >> b;
    cout << 30 + max_((((r + 1) >> 1) - 1) * 3, (((g + 1) >> 1) - 1) * 3 + 1, (((b + 1) >> 1) - 1) * 3 + 2);
    return 0;
}