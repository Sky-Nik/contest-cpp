#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n - 1);
    for (auto& ai: a) {
        cin >> ai;
        --ai;
    }

    cout << a[0] + 1 << "\n";

    vector<bool> used(n, false);
    int most_importnant = n - 1;

    for (int i = 0; i + 1 < n; ++i) {
        used[a[i]] = true;

        while (used[most_importnant])
            --most_importnant;

        if (i + 1 == n - 1 || used[a[i + 1]]) {
            cout << a[i] + 1 << " " << most_importnant + 1 << "\n";
            used[most_importnant] = true;
        } else {
            cout << a[i + 1] + 1 << " " << a[i] + 1 << "\n";
        }
    }

    return 0;
}
