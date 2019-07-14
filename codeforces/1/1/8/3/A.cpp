#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int sum_of_digits(int a) {
    int s = 0;
    while (a > 0) {
        s += a % 10;
        a /= 10;
    }
    return s;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a;
    cin >> a;
    for (int i = 0; i < 10; ++i) {
        if (sum_of_digits(a + i) % 4 == 0) {
            cout << a + i;
            return 0;
        }
    }
}