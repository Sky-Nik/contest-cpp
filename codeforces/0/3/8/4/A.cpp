#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << ((n * n + 1) >> 1) << "\n";;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i + j) & 1) {
                cout << ".";
            } else {
                cout << "C";
            }
        }
        cout << "\n";
    }
    return 0;
}