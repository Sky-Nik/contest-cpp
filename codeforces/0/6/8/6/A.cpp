#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x;
    cin >> n >> x;
    int sad = 0;
    char c;
    for (int i = 0, d; i < n; ++i) {
        cin >> c >> d;
        if (c == '+') {
            x += d;
        } else {
            if (x >= d) {
                x -= d;
            } else {
                ++sad;
            }
        }
    }
    cout << x << " " << sad;
    return 0;
}