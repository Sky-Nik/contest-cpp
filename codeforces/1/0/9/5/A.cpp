#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string t;
    cin >> t;
    for (int i = 0; (i * (i + 1) >> 1) < n; ++i) {
        cout << t[i * (i + 1) >> 1];
    }
    return 0;
}