#include <bits/stdc++.h>
using namespace std;

template<typename T>
T min_(T t) {
    return t;
}

template<typename T, typename... Args>
T min_(T t, Args... args) {
    return min(t, min_(args...));
}

int main() {
    int k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;
    int k256 = min_(k2, k5, k6);
    k2 -= k256;
    int k32 = min_(k2, k3);
    cout << (k32 << 5) + (k256 << 8);
    return 0;
}