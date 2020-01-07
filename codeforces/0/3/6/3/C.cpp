#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    string t;
    int tl = 0;
    for (auto c: s) {
        if (tl >= 2) {
            if (c == t[tl - 1] && t[tl - 1] == t[tl - 2] ) {
                continue;
            }
        }

        if (tl >= 3) {
            if (c == t[tl - 1] && t[tl - 2] == t[tl - 3]) {
                continue;
            }
        }

        t += c;
        ++tl;
    }

    cout << t;

    return 0;
}
