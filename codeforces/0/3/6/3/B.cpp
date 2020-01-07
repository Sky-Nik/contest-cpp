#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (auto& hi: h)
        cin >> hi;


    int sh = 0;
    for (int i = 0; i < k; ++i)
        sh += h[i];
    int msh = sh;
    int j = 0;

    for (int i = k; i < n; ++i) {
        sh += h[i];
        sh -= h[i - k];
        if (sh < msh) {
            msh = sh;
            j = i - k + 1;
        }
    }

    cout << j + 1;

    return 0;
}
