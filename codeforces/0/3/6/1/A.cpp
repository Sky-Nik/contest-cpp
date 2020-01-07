#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (r == c) {
                cout << k << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << "\n";
    }

    return 0;
}
