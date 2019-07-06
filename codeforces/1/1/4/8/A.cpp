#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << ((c + min(a, b)) << 1) + ((a != b) ? 1 : 0);
    return 0;
}