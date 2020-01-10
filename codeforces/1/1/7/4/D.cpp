#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    int k = 1 << n;

    if (x >= k) {
        cout << k - 1 << "\n";
    
        vector<int> b(k - 1);
        for (int i = 1; i < k; ++i)
            b[i - 1] = i;

        if (!b.empty()) {
            cout << b[0];

            for (int i = 1; i < b.size(); ++i)
                cout << " " << (b[i - 1] ^ b[i]);
        }
    } else {
        cout << ((k - 2) >> 1) << "\n";

        set<int> b1, b2;

        for (int i = 1; i < k; ++i)
            b1.insert(i);

        for (int bi: b1) {
            b2.insert(bi);

            if (b2.find(x ^ bi) != b2.end())
                b2.erase(x ^ bi);
        }

        if (b2.find(x) != b2.end())
            b2.erase(x);

        vector<int> b(b2.begin(), b2.end());

        if (!b.empty()) {
            cout << b[0];

            for (int i = 1; i < b.size(); ++i)
                cout << " " << (b[i - 1] ^ b[i]);
        }
    }
 
    return 0;
}
