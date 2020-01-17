#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --> 0) {
        int m, n;
        cin >> m >> n;

        vector<string> b(m);
        for (auto& bi: b)
            cin >> bi;

        vector<int> s(n);
        for (auto& si: s)
            cin >> si;

        vector<int> p(n);
        for (auto& pi: p)
            cin >> pi;

        cout << n << "\n";

        for (int i = 0; i < n; ++i)
            cout << 1 << " " << s[i] << " " << i + 1 << "\n";
    }

    return 0;
}
