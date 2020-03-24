/* INPUT
6
3 1
4 2
10 3
10 2
16 4
16 5
->
YES
YES
NO
YES
YES
NO
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t --> 0) {
        int64_t n, k;
        cin >> n >> k;
        if (n % 2 != k % 2) {
            cout << "NO\n";
        } else {
            if (k * k <= n) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
