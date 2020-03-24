#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t --> 0) {
        int n, a;
        cin >> n >> a;

        bool x = false;

        while (n --> 1) {
            int b;
            cin >> b;
            x |= (a - b) & 1;
        }

        if (x) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0; 
}
