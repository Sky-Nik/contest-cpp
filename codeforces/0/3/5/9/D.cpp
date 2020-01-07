#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), w;
    for (auto& ai: a)
        cin >> ai;

    int b = 0;
    for (int i = 0; i < n;) {
        int r = i, l = i;

        while (l && !(a[l - 1] % a[i]))
            --l;

        while (r< n- 1 && !(a[r + 1] % a[i]))
            ++r;

        i = r + 1;
        r -= l;

        if (r > b) {
            w.clear();
            b = r;
        }

        if (r == b) {
            w.push_back(l + 1);
        }
    }

    cout << w.size() << " " << b << "\n";
    
    for (auto wi: w)
        cout << wi << " ";
    
    return 0;
}
