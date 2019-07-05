#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int k = 1;
    while ((k & 1) ? (a >= k) : (b >= k)) {
        if (k & 1) {
            a -= k;
        } else {
            b -= k;
        }
        ++k;
    }
    if (k & 1) {
        cout << "Vladik";
    } else {
        cout << "Valera";
    }
    return 0;
}