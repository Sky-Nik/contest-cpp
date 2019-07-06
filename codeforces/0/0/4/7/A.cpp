#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    bool found = false;
    for (int k = 0; !found && (k <= n); ++k) {
        if (n == ((k * (k + 1)) >> 1)) {
            found = true;
        }
    }
    if (found) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}