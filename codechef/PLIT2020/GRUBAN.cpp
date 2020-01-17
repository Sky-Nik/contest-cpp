#include <bits/stdc++.h>
using namespace std;

int64_t solve(int64_t n, int64_t k) {
    int64_t r = -1;

    int64_t sk = ((k + 1) * k) >> 1;

    for (int64_t d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            int64_t g1 = d;
            if (sk * g1 <= n)
                r = max(r, g1);

            int64_t g2 = n / d;
            if (sk * g2 <= n)
                r = max(r, g2);
        }
    }

    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t t;
    cin >> t;

    while (t --> 0) {
        int64_t n, k;
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }

    return 0;
}