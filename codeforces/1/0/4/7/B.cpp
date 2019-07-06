#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a = 0;
    for (int i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        a = max(a, x + y);
    }
    cout << a;
    return 0;
}