#include <bits/stdc++.h>
using namespace std;
#define elif else if
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x, y;
    cin >> n >> x >> y;
    if (x + y <= n + 1) {
        cout << "White";
    } else {
        cout << "Black";
    }
    return 0;
}
