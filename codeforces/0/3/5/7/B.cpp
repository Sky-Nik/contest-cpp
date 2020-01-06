#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> c(n, 0);
    for (int i = 0; i < m; ++i) {
        int ai, bi, ci;
        cin >> ai >> bi >> ci;
        --ai;
        --bi;
        --ci;
        if (c[ai]) {
            if (c[ai] == 1) {
                c[bi] = 2;
                c[ci] = 3;
            } else if (c[ai] == 2) {
                c[bi] = 1;
                c[ci] = 3;
            } else {
                c[bi] = 1;
                c[ci] = 2;
            }
        } else if (c[bi]) {
            if (c[bi] == 1) {
                c[ai] = 2;
                c[ci] = 3;
            } else if (c[bi] == 2) {
                c[ai] = 1;
                c[ci] = 3;
            } else {
                c[ai] = 1;
                c[ci] = 2;
            }
        } else if (c[ci]) {
            if (c[ci] == 1) {
                c[ai] = 2;
                c[bi] = 3;
            } else if (c[ci] == 2) {
                c[ai] = 1;
                c[bi] = 3;
            } else {
                c[ai] = 1;
                c[bi] = 2;
            }
        } else {
            c[ai] = 1;
            c[bi] = 2;
            c[ci] = 3;
        }
    }

    for (auto& ci: c) cout << ci << " ";

    return 0;
}
