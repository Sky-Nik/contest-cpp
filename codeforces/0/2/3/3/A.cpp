#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n & 1) {
        cout << -1;
    } else {
        for (int i = 0; i < n; ++i) {
            cout << i + ((i & 1) ? 0 : 2) << " ";
        }
    }
    return 0;
}