#include <bits/stdc++.h>
using namespace std;

struct s {
    int l, r, w;  // [l, r)
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n);
    for (auto& xi: x)
        cin >> xi;

    vector<int> cnt(n + 2, 0);
    for (auto xi: x)
        ++cnt[xi];

    int mmin = 0;
    for (int i = 0; i < n + 2; ++i) {
        if (cnt[i]) {
            ++mmin;
            i += 2;
        }
    }

    cout << mmin << " ";

    vector<s> ss; 
    for (int i = 0; i < n + 2; ++i) {
        int l = i, w = 0;

        while (cnt[i]) {
            w += cnt[i];
            ++i;
        }

        if (w)
            ss.push_back({l, i, w});
    }

    for (int i = 0; i < ss.size(); ++i) {
        if (ss[i].w >= ss[i].r - ss[i].l + 2) {
            if (i == 0 || ss[i - 1].r < ss[i].l)
                --ss[i].l;
            if (i + 1 == ss.size() || ss[i + 1].l > ss[i].r)
                ++ss[i].r;
        } else if (ss[i].w >= ss[i].r - ss[i].l + 1) {
            if (i == 0 || ss[i - 1].r < ss[i].l)
                --ss[i].l;
            else if (i + 1 == ss.size() || ss[i + 1].l > ss[i].r)
                ++ss[i].r;
        }
    }

    int mmax = 0;
    for (auto s: ss)
        mmax += s.r - s.l; 

    cout << mmax;

    return 0;
}
