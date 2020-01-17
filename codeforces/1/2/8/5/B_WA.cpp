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

        vector<int> ps(n, 0);
        for (int i = 0; i + 1 < n; ++i)
            ps[i + 1] = ps[i] + a[i];

        ps[0] = numeric_limits<int>::max();

        bool pb = false;
        for (auto pi: ps)
            if (pi <= 0)
                pb = true; 

        reverse(a.begin(), a.end());

        vector<int> ss(n, 0);
        for (int i = 0; i + 1 < n; ++i)
            ss[i + 1] = ss[i] + a[i];

        ss[0] = numeric_limits<int>::max();

        bool sb = false;
        for (auto si: ss)
            if (si <= 0)
                sb = true;

        if (pb || sb)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}