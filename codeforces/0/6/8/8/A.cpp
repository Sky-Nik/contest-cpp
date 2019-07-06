#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    string b;
    int ma = 0, a = 0;
    for (int i = 0; i < d; ++i) {
        cin >> b;
        bool ia = false;
        for (int j = 0; j < n; ++j) {
            if (b[j] == '0') {
                ia = true;
            }
        }
        if (ia) {
            ++a;
        } else {
            ma = max(ma, a);
            a = 0;
        }
    }
    cout << max(ma, a);;
    return 0;
}