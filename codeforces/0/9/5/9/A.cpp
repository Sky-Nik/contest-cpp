#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n & 1)
        cout << "Ehab";
    else
        cout << "Mahmoud";

    return 0;
}