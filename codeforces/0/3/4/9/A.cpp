#include <bits/stdc++.h>
using namespace std;
int n, a = 0, b = 0, d;
bool f = true;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n --> 0) {
        cin >> d;
        if (d == 25) {
            ++a;
        } else if (d == 50) {
            if (a > 0) {
                --a;
                ++b;
            } else {
                f = false;
            }
        } else if (b > 0 && a > 0) {
            --a;
            --b;
        } else if (a >= 3) {
            a -= 3;
        } else {
            f = false;
        }
    }
    if (f) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
