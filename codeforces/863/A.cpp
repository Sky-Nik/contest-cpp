#include <bits/stdc++.h>
using namespace std;
int main() {
    int x;
    cin >> x;
    while (x % 10 == 0) {
        x /= 10;
    }
    vector<int> digits;
    while (x > 0) {
        digits.push_back(x % 10);
        x /= 10;
    }
    bool ok = true;
    for (int i = 0; i < digits.size(); ++i) {
        if (digits[i] != digits[digits.size() - 1 - i]) {
            ok = false;
        }
    }
    cout << (ok ? "YES" : "NO");
    return 0;
}