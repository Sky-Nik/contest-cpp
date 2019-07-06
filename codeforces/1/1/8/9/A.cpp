#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    int c0 = 0, c1 = 0;
    for (char c: s) {
        if (c == '0') {
            ++c0;
        } else {
            ++c1;
        }
    }
    if (c0 == c1) {
        cout << 2 << "\n";
        cout << s[0] << " " << s.substr(1, n - 1);
    } else {
        cout << 1 << "\n" << s;
    }
    return 0;
}