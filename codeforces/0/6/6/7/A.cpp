#include <bits/stdc++.h>

using namespace std;

typedef long double ldouble;

# define M_PI           3.14159265358979323846  /* pi */

int main() {
    int d, h, v, e;
    cin >> d >> h >> v >> e;
    ldouble s = (M_PI / 4) * d * d;
    if (v / s <= e) {
        cout << "NO";
    } else {
        cout << "YES\n" << fixed << setprecision(9) << h / (v / s - e);
    }
    return 0;
}