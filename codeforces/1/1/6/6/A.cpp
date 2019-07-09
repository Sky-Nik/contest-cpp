#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> f(26, 0);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ++f[s[0] - 'a'];
    }
    int a = 0;
    for (int i = 0; i < 26; ++i) {
        int b = f[i] >> 1;
        a += (f[i] - b) * (f[i] - b - 1) + b * (b - 1);
    }
    cout << (a >> 1);
    return 0;
}
