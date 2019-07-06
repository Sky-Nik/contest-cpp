#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int win = 0, draw = 0, lose = 0;
    for (int i = 1; i <= 6; ++i) {
        int d1 = abs(a - i), d2 = abs(b - i);
        if (d1 < d2) {
            ++win;
        } else if (d1 == d2) {
            ++draw;
        } else {
            ++lose;
        }
    }
    cout << win << " " << draw << " " << lose;
    return 0;
}