#include <bits/stdc++.h>
using namespace std;
#define elif else if
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool possible = false;
    int idx = -1;
    for (int i = 0; !possible && i + 1 < n; ++i) {
        if (s[i] > s[i + 1]) {
            possible = true;
            idx = i + 1;
        }
    }
    if (possible) {
        cout << "YES\n" << idx << " " << idx + 1;
    } else {
        cout << "NO";
    }

    return 0;
}