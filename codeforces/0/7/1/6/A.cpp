#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, c;
    cin >> n >> c;
    int a = 0;
    for (int i = 0, t1 = 1, t2; i < n; ++i) {
        cin >> t2;
        if (t2 - t1 > c) {
            a = 1;
        } else {
            ++a;
        }
        t1 = t2;
    }
    cout << a;
    return 0;
}