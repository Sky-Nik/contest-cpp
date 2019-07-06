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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    cout << 7 * min_(a, b >> 1, c >> 2);
    return 0;
}