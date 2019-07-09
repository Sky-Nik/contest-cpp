#include <bits/stdc++.h>
using namespace std;
#define elif else if
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "Yes";
        return 0;
    }
    string s;
    cin >> s;
    vector<int> f(26, 0);
    for (int i = 0; i < n; ++i) {
        ++f[s[i] - 'a'];
    }
    bool possible = false;
    for (int i = 0; i < 26; ++i) {
        if (f[i] > 1) {
            possible = true;
        }
    }
    if (possible) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
