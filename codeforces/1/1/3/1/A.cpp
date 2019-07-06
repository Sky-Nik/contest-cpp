#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    cout << ((w1 + h1 + h2) << 1) + 4;
    return 0;
}