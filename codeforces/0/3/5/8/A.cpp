#include <bits/stdc++.h>
using namespace std;

struct s {
    int l, r;
};

bool i(const s& s1, const s& s2) {
    return (s1.l < s2.l && s2.l < s1.r && s1.r < s2.r) ||
        (s2.l < s1.l && s1.l < s2.r && s2.r < s1.r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> x(n);
    for (auto& xi: x) cin >> xi;

    vector<s> ss(n - 1);
    for (int i = 0; i + 1 < n; ++i) {
        ss[i].l = min(x[i], x[i + 1]);
        ss[i].r = max(x[i], x[i + 1]);
    }

    bool flag = false;
    for (auto si: ss) {
        for (auto sj: ss) {
            flag |= i(si, sj);
        }
    }

    if (flag) {
        cout << "yes";
    } else {
        cout << "no";
    }

    return 0;
}
