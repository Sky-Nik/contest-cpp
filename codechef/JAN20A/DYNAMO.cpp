#include <bits/stdc++.h>
using namespace std;

int64_t mpow(int64_t n, int64_t p) {
    int64_t r = 1LL;

    for (int i = 0; i < p; ++i)
        r *= n;

    return r;
}

int main() {
    int64_t t, n, a, b, c, d, e, s, r;
    cin >> t;

    while (t --> 0) {
        cin >> n;
        cin >> a;

        s = 2 * mpow(10, n) + a;
        cout << s << "\n" << flush;

        cin >> b;

        c = mpow(10, n) - b;
        cout << c << "\n" << flush;

        cin >> d;

        e = mpow(10, n) - d;
        cout << e << "\n" << flush;

        cin >> r;
        if (r == -1)
            return 1;
    }
    
    return 0;
}
