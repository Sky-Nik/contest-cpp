/* INPUT
1
->
10

2
->
180 10

3
->
2610 180 10

4
->
34200 2610 180 10

10
->
943963054 482289529 666000000 58500000 5040000 423000 34200 2610 180 10
*/

#include <bits/stdc++.h>
using namespace std;

const int64_t mod = 998'244'353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int64_t> a = {10};
    int64_t s = 10, t = 10, p = 10, p10 = 10;

    for (int i = 1; i < n; ++i) {
        p10 = (10 * p10) % mod; 
        p = (10 * p + p10) % mod;
        t = (t + s) % mod;
        a.push_back((p - t + mod) % mod);
        s = (s + a.back()) % mod;
        t = (t + a.back()) % mod;
    }

    reverse(a.begin(), a.end());

    for (auto ai : a) {
        cout << ai << " ";
    }

    return 0;
}
