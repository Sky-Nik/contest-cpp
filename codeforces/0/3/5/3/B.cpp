#include <bits/stdc++.h>
using namespace std;

struct cub {
    int dup;
    int num;
    int idx;

    bool operator<(const cub& o) const {
        return make_tuple(dup, num, idx) < make_tuple(o.dup, o.num, o.idx);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<cub> a(n << 1);
    for (int i = 0; i < (n << 1); ++i) {
        cin >> a[i].num;
        a[i].idx = i;
        a[i].dup = 1;
    }

    for (int i = 0; i < (n << 1); ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i].num == a[j].num) {
                a[i].dup = 0;
                a[j].dup = 0;
            }
        }
    }

    sort(a.begin(), a.end());

    vector<int> p(n << 1);
    set<int> lhs, rhs;
    for (int i = 0; i < (n << 1); ++i) {
        p[a[i].idx] = 2 - (i & 1);
        if (i & 1) {
            lhs.insert(a[i].num);
        } else {
            rhs.insert(a[i].num);
        }
    }

    cout << lhs.size() * rhs.size() << "\n";
    for (auto pi: p) cout << pi << " ";

    return 0;
}
