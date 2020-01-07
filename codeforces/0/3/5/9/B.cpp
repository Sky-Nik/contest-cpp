#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n << 1);
    for (int i = 0; i < (n << 1); ++i)
        a[i] = i;

    for (int j = 0; j < k; ++j)
        swap(a[j << 1], a[(j << 1) | 1]);

    for (auto ai: a)
        cout << ai + 1 << " ";

    return 0;
}
