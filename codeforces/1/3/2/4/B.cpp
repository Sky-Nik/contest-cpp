#include <bits/stdc++.h>
using namespace std;

bool pal(int n, const vector<int>& a) {
    bool ans = false;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 2; j < n; ++j) {
            ans |= a[i] == a[j];
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t --> 0) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto& ai : a) {
            cin >> ai;
        }

        if (pal(n, a)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}