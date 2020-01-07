#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> t(m), l(m), r(m), d(m), M(m);
    for (int i = 0; i < m; ++i) {
        cin >> t[i];
        if (t[i] == 1)
            cin >> l[i] >> r[i] >> d[i];
        else
            cin >> l[i] >> r[i] >> M[i];
        --l[i];
        --r[i];
    }

    vector<int> a(n, numeric_limits<int>::max()), s(n, 0);
    for (int i = 0; i < m; ++i) {
        if (t[i] == 1)
            for (int j = l[i]; j <= r[i]; ++j)
                s[j] += d[i];
        else
            for (int j = l[i]; j <= r[i]; ++j)
                a[j] = min(a[j], M[i] - s[j]);
    }

    for (int i = 0; i < n; ++i)
        if (a[i] == numeric_limits<int>::max())
            a[i] = 0;

    vector<int> b = a;
    bool possible = true;
    for (int i = 0; i < m; ++i) {
        if (t[i] == 1)
            for (int j = l[i]; j <= r[i]; ++j)
                b[j] += d[i]; 
        else {
            int Max = numeric_limits<int>::min();
            for (int j = l[i]; j <= r[i]; ++j)
                Max = max(b[j], Max);
            // cout << "M[" << i << "] = " << M[i] << ", Max = " << Max << "\n";
            possible &= M[i] == Max;
        }
    }

    if (possible) {
        cout << "YES\n";
        for (auto ai: a)
            cout << ai << " ";
    } else {
        cout << "NO\n";
        // for (auto ai: a)
        //     cout << ai << " ";
    } 

    return 0;
}
