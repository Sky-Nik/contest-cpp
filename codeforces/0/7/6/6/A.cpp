#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    if (a == b)
        cout << -1;
    else
        cout << max(a.length(), b.length());

    return 0;
}
