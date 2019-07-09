#include <bits/stdc++.h>
using namespace std;
#define elif else if
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    int neg = 0, pos = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > 0) {
            ++pos;
        } elif (a[i] < 0) {
            ++neg;
        }
    }
    if (pos >= ((n + 1) >> 1)) {
        cout << 1;
    } elif (neg >= ((n + 1) >> 1)) {
        cout << -1;
    } else {
        cout << 0;
    }
    return 0;
}
