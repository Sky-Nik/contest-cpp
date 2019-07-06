#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '+') {
            ++c;
        } else {
            --c;
            m = min(m, c);
        }
    }
    cout << c - m;
    return 0;
}