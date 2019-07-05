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
    int y, b, r;
    cin >> y >> b >> r;
    cout << 3 * min_(y + 1, b, r - 1);
    return 0;
}