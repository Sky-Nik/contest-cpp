#include <bits/stdc++.h>
using namespace std;

string product(int i, int j, int k) {
    string ans;

    int n = i * j;
    while (n) {
        ans = (char)(n % k + '0') + ans;
        n /= k;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;

    for (int i = 1; i < k; ++i) {
        for (int j = 1; j < k; ++j) {
            cout << product(i, j, k) << " ";
        }
        cout << "\n";
    }

    return 0;
}
