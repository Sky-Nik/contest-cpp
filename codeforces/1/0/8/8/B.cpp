#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> aa(n);
    for (auto& ai: aa)
        cin >> ai;

    set<int> sa;
    for (auto ai: aa)
        sa.insert(ai);

    vector<int> a(1, 0);
    for (auto sai: sa)
        a.push_back(sai);

    sort(a.begin(), a.end());

    vector<int> d(k, 0);
    for (int i = 0; i + 1 < a.size(); ++i)
        if (i < k)
            d[i] = a[i + 1] - a[i];

    for (auto di: d)
        cout << di << "\n";

    return 0;
}