#include <bits/stdc++.h>
using namespace std;
#define elif else if
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string t, s = "";
    cin >> t;
    int i = 0, j = t.length() - 1, k = t.length();
    while (k--) {
        s += (k & 1) ? t[j--] : t[i++];
    }
    reverse(begin(s), end(s));
    cout << s;
    return 0;
}
