#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int l, r;
    for (l = 0; l < t.length() && s[l] == t[l];)
        ++l;

    for (r = t.length() - 1; r >= 0 && s[r + 1] == t[r];)
        --r;

    if (l <= r)
        cout << 0;
    else {
        cout << l - r << "\n";
        for (int i = r + 1; i <= l; ++i)
            cout << i + 1 << " ";
    }
    return 0;
}
