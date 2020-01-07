#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    if (k == n) {
        cout << -1;
    } else {
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            a[i] = i + 1;
        for (int i = k + 1; i + 1 < n; i += 2)
            swap(a[i], a[i + 1]);
        if (k != n - 1 && a[n - 1] == n)
            swap(a[0], a[n - 1]);

        for (auto ai: a)
            cout << ai << " ";
    }

    return 0;
}
