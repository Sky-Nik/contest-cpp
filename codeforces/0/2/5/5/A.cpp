#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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
    int n;
    cin >> n;
    int chest = 0, biceps = 0, back = 0;
    for (int i = 0, ai; i < n; ++i) {
        cin >> ai;
        if (i % 3 == 0) {
            chest += ai;
        } else if (i % 3 == 1) {
            biceps += ai;
        } else {
            back += ai;
        }
    }
    int m = max_(chest, biceps, back);
    if (chest == m) {
        cout << "chest";
    } else if (biceps == m) {
        cout << "biceps";
    } else {
        cout << "back";
    }
    return 0;
}