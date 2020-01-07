#include <bits/stdc++.h>
using namespace std;

void print_soroban(int n) {
    if (n >= 5)
        cout << "-O|";
    else
        cout << "O-|";

    n %= 5;

    for (int i = 0; i < n; ++i)
        cout << "O";

    cout << "-";

    for (int i = n; i < 4; ++i)
        cout << "O";

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if (!n) {
        cout << "O-|-OOOO";
    }

    while (n) {
        print_soroban(n % 10);
        n /= 10;
    }

    return 0;
}
