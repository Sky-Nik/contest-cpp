#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] >= 0) {
            a[i] = -a[i] - 1;
        }
    }
    if (n & 1) {
        int min_idx = 0, min_num = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] < min_num) {
                min_num = a[i];
                min_idx = i;
            }
        }
        a[min_idx] = -a[min_idx] - 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}