#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n << 1);
    for (auto& ai: a)
        cin >> ai;
    
    set<int> sa;
    for (auto ai: a)
        sa.insert(ai);

    if (sa.size() > 1) {
        sort(a.begin(), a.end());

        for (auto ai: a)
            cout << ai << " ";
    } else {
        cout << -1;
    }

    return 0;
}
