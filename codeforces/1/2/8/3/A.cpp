#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t --> 0) {
        int h, m;
        cin >> h >> m;
        cout << 60 * 24 - (h * 60 + m) << "\n";
    }

    return 0;
}
