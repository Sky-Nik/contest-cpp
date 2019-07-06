#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int h = 1, v = 1;
    while (h * v < n) {
        if ((h & 1) == (v & 1)) {
            ++h;
        } else {
            ++v;
        }
    }
    cout << ((h + v) << 1);
    return 0;
}
