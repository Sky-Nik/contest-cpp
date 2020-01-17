#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --> 0) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto& ai: a)
            cin >> ai;

        vector<int> p(n + 1, 0);
        for (int i = 0; i < n; ++i)
            p[i + 1] = p[i] + (a[i] & 1);

        int q;
        cin >> q;

        while (q --> 0) {
            int l, r;
            cin >> l >> r;

            if (p[r] - p[l - 1] == r - l + 1) {
                cout << "ODD\n";
            } else {
                cout << "EVEN\n";
            }
        }
    }

    return 0;
}