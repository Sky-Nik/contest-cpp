#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n, 0);

    int k = 0;

    for (int d = 2; d <= n; ++d) {
        if (!a[d - 1]) {
            ++k;

            for (int i = d - 1; i < n; i += d)
                a[i] = k;
        }
    }

    for (int i = 1; i < n; ++i)
        cout << a[i] << " ";

    return 0;
}
