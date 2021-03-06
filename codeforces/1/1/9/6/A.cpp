#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define forn(i, n) for(int i = 0; i < n; ++i)

template<typename T>
T min_(T t) {
    return t;
}

template<typename T, typename... Args>
T min_(T t, Args... args) {
    return min(t, min_(args...));
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
    int q;
    cin >> q;
    forn(iq, q) {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << min_((a + b + c) >> 1, max_(a + b, b + c, c + a)) << "\n";
    }
    return 0;
}