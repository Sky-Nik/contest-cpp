#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    set<int> alive;
    vector<int> answer(n, -1);
    for (int i = 0; i < n; ++i) alive.insert(i);

    for (int i = 0; i < m; ++i) {
        int li, ri, xi;
        cin >> li >> ri >> xi;
        --li; --ri; --xi;

        vector<int> to_erase;

        for (auto it = alive.lower_bound(li); it != alive.end(); ++it) {
            int cur = *it;
            if (cur > ri) {
                break;
            }

            if (cur != xi) {
                to_erase.push_back(cur);
                answer[cur] = xi;
            }
        }

        for (auto ti: to_erase) alive.erase(ti);
    }

    for (auto ai: answer) cout << ai + 1 << " ";

    return 0;
}
