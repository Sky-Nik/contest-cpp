#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;

    int n, m;
    cin >> n >> m;

    vector<int64_t> a(n), b(m);
    for (auto& ai: a) {
        cin >> ai;
        ai = min(ai * c1, c2);
    }
    for (auto& bj: b) {
        cin >> bj;
        bj = min(bj * c1, c2);
    }

    int64_t ca = min(accumulate(a.begin(), a.end(), 0LL), c3),
        cb = min(accumulate(b.begin(), b.end(), 0LL), c3);

    cout << min(ca + cb, c4);

    return 0;
}
