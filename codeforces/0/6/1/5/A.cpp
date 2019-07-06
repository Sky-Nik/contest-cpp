#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
bool all(vector<T>& v) {
    for (const T& e: v) {
        if (!e) {
            return false;
        }
    }
    return true;
}

template<typename T>
bool any(vector<T>& v) {
    for (const T& e: v) {
        if (e) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<bool> on(m, false);
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        for (int j = 0, y; j < x; ++j) {
            cin >> y;
            on[y - 1] = true;
        }
    }
    if (all(on)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}