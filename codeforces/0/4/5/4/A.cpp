#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (abs(i - (n >> 1)) + abs(j - (n >> 1)) <= (n >> 1)) {
                cout << "D";
            } else {
                cout << "*";
            }
        }
        cout << "\n";
    }
    return 0;
}