#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = 0, r = n - 1;
    int s = 0, d = 0;
    for (int k = 0; k < n; ++k) {
        if (k & 1) {
            if (a[l] > a[r]) {
                d += a[l];
                ++l;
            } else {
                d += a[r];
                --r;
            }
        } else {
            if (a[l] > a[r]) {
                s += a[l];
                ++l;
            } else {
                s += a[r];
                --r;
            }
        }
    }
    cout << s << " " << d;
    return 0;
}