#include <bits/stdc++.h>
using namespace std;
#define elif else if
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    double k, n, s, p;
    cin >> k >> n >> s >> p;
    cout << (ll)(ceil(k * ceil(n / s) / p));
    return 0;
}
