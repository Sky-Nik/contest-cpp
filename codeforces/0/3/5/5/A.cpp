#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, d;
    cin >> k >> d;

    if (d == 0) {
        if (k == 1) {
            cout << 0;
        } else {
            cout << "No solution";
        }
    } else {
        cout << d;
        for (int i = 0; i + 1 < k; ++i) {
            cout << 0;
        }
    }

    return 0;
}
