#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> f(n);
    for (auto& fi: f)
        cin >> fi;

    vector<int> p(n, 0);
    for (int i = 0; i < n; ++i)
        if (f[i])
            p[f[i] - 1] = i + 1;

    // cout << "p: ";
    // for (auto pi: p)
    //     cout << pi << " ";
    // cout << "\n";

    vector<int> ff;
    for (int i = 0; i < n; ++i)
        if (!f[i])
            ff.push_back(i);

    // cout << "ff: ";
    // for (auto ffi: ff)
    //     cout << ffi << " ";
    // cout << "\n";

    sort(ff.begin(), ff.end());

    vector<int> pf;
    for (int i = 0; i < n; ++i)
        if (!p[i])
            pf.push_back(i + 1);

    // cout << "pf: ";
    // for (auto pfi: pf)
    //     cout << pfi << " ";
    // cout << "\n";

    sort(pf.rbegin(), pf.rend());

    int j = -1;

    for (int i = 0; i < ff.size(); ++i) {
        if (ff[i] + 1 == pf[i])
            j = i;
        f[ff[i]] = pf[i];
    }

    if (j != -1) {
        if (j > 0)
            swap(f[ff[j]], f[ff[j - 1]]);
        else
            swap(f[ff[j]], f[ff[j + 1]]);
    }

    for (auto fi: f)
        cout << fi << " ";

    return 0;
}
