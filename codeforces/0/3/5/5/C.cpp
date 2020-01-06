#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n, l, r, ql, qr;
    cin >> n >> l >> r >> ql >> qr;

    vector<int64_t> w(n), pw(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        pw[i + 1] = pw[i] + w[i];
    }

    int64_t answer = numeric_limits<int64_t>::max(), current;

    for (int i = 0; i <= n; ++i) {
        current = pw[i] * l + (pw[n] - pw[i]) * r;
        // cout << "i = " << i << ", current = " << current << "\n";
        if ((i << 1) < n) {
            current += qr * (n - (i << 1) - 1);
        }
        // cout << "current with qr = " << current << "\n";
        if ((i << 1) > n) {
            current += ql * ((i << 1) - n - 1);
        }
        // cout << "current with ql = " << current << "\n";
        answer = min(answer, current);
    } 
    
    cout << answer;

    return 0;
}
