#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int i = 0;
    while (m >= (i + 1)) {
        m -= (i + 1);
        ++i;
        i %= n;
    }
    cout << m;
    return 0;
}