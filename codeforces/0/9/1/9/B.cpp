#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int k;

bool check(int n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s == 10;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k;
    int i = 0, n = 0;
    while (i < k) {
        ++n;
        if (check(n)) {
            ++i;
        }
    }
    cout << n;
    return 0;
}
