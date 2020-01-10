#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai: a)
        cin >> ai;

    sort(a.begin(), a.end());

    bool possible = false;

    for (int i = 0; i + 2 < n; ++i)
        if (a[i + 2] < a[i + 1] + a[i])
            possible = true;

    if (possible)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
