#include <bits/stdc++.h>
using namespace std;

const int64_t mod = 1'000'000'007;

int64_t binary_pow(int64_t x, int64_t v) {
    if (!v)
        return 1;

    if (v & 1)
        return (x * binary_pow(x, v - 1)) % mod;

    int64_t r = binary_pow(x, v >> 1);
    return (r * r) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n, x;
    cin >> n >> x;
    vector<int64_t> a(n);
    for (auto& ai: a)
        cin >> ai;

    int64_t s = accumulate(a.begin(), a.end(), 0LL);
    
    vector<int64_t> b(n);
    
    for (int i = 0; i < n; ++i)
        b[i] = s - a[i];
    
    sort(b.begin(), b.end(), greater<int64_t>());

    while (!b.empty()) {
        int64_t v = b.back();

        int64_t cnt = 0;

        while (!b.empty() && b.back() == v) {
            ++cnt;
            b.pop_back();
        }

        if (cnt % x) {
            v = min(v, s);
            cout << binary_pow(x, v);
            return 0;
        } else {
            cnt /= x;
            for (int i = 0; i < cnt; ++i)
                b.push_back(v + 1);
        }
    }

    return 0;
}
