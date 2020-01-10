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

    bool has_even = false, has_odd = false;

    for (auto ai: a)
        if (ai & 1)
            has_odd = true;
        else
            has_even = true;

    if (has_even && has_odd) {
        sort(a.begin(), a.end());

        for (auto ai: a)
            cout << ai << " ";
    } else {
        for (auto ai: a)
            cout << ai << " ";
    }

    return 0;
}
