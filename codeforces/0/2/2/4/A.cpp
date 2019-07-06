#include <bits/stdc++.h>

using namespace std;

int main() {
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int e1 = sqrt(s2 * s3 / s1) + .01,
        e2 = sqrt(s1 * s3 / s2) + .01,
        e3 = sqrt(s1 * s2 / s3) + .01;
    cout << ((e1 + e2 + e3) << 2);
    return 0;
}