#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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
    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;
    cout << min_((d1 + d2) << 1, d1 + d2 + d3, (d1 + d3) << 1, (d2 + d3) << 1);
    return 0;
}