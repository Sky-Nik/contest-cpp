#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    if (!m) {
        cout << "YES";
        return 0;
    }

    vector<int> d(m);
    for (auto& di: d)
        cin >> di;

    sort(d.begin(), d.end());
    if (d[0] == 1 || d[m - 1] == n) {
        cout << "NO";
    } else {
        bool possible = true;
        for (int i = 0; i + 2 < m; ++i)
            if (d[i] + 1 == d[i + 1] && d[i + 1] + 1 == d[i + 2])
                possible = false;

        if (possible)
            cout << "YES";
        else
            cout << "NO";
    }

    return 0;
}
