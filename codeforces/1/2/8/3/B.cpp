#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t --> 0) {
        int64_t n, k;
        cin >> n >> k;
        int64_t a = (n / k) * k;
        n %= k;
        a += min(n, k / 2);
        cout << a << "\n";
    }

    return 0;
}
