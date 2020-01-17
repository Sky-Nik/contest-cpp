#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t x;
    cin >> x;

    int64_t r = x;

    for (int64_t a = 1; a * a <= x; ++a)
        if (x % a == 0 && gcd(a, x / a) == 1)
            r = x / a;

    cout << x / r << " " << r;

    return 0;
}