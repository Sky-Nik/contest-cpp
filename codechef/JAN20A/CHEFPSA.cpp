#include <bits/stdc++.h>
using namespace std;

const int64_t kMod = 1'000'000'007LL;

int64_t bin_pow(int64_t n, int64_t pw) {
    if (!pw)
        return 1;

    if (pw & 1)
        return (n * bin_pow(n, pw - 1)) % kMod;

    return bin_pow((n * n) % kMod, pw >> 1);
}

int64_t inv(int64_t n) {
    return bin_pow(n, kMod - 2);
}

const int64_t kMaxN = 100'100;

int64_t f[kMaxN], p[kMaxN], invf[kMaxN];

int64_t CalculateAnswerC(const vector<int64_t>& c, int64_t c0) {
    int64_t r = f[accumulate(c.begin(), c.end(), 0) + c0] % kMod;

    for (const auto ci: c) {
        r *= invf[ci];
        r %= kMod;
        r *= p[ci];
        r %= kMod;
    }

    r *= invf[c0];
    r %= kMod;

    return r;
}

int64_t CalculateAnswer(const map<int64_t, int64_t>& cnt, int64_t s) {
    vector<int64_t> c;
    int64_t c0 = 0;

    for (const auto kv: cnt) {
        auto k = kv.first;
        auto v = kv.second;

        if (k < s - k && v)
            c.push_back(v);
        else if (k << 1 == s)
            c0 = v >> 1;
    }

    return CalculateAnswerC(c, c0);
}

map<int64_t, int64_t> BuildCounter(const vector<int64_t>& x) {
    map<int64_t, int64_t> cnt;

    for (const auto xi: x) {
        if (cnt.find(xi) == cnt.end())
            cnt[xi] = 0;

        ++cnt[xi];
    }

    return cnt;
}

bool CheckCounterInvariants(map<int64_t, int64_t>& cnt, int64_t s) {
    if (cnt[s] < 2)
        return false;

    cnt[s] -= 2;

    for (const auto kv: cnt) {
        auto k = kv.first;

        if (k << 1 == s && cnt[k] & 1 || cnt[s - k] != cnt[k])
            return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    f[0] = 1;
    for (int64_t i = 1; i < kMaxN; ++i)
        f[i] = (i * f[i - 1]) % kMod;

    p[0] = 1;
    for (int64_t i = 1; i < kMaxN; ++i)
        p[i] = (p[i - 1] << 1) % kMod;

    for (int64_t i = 0; i < kMaxN; ++i)
        invf[i] = inv(f[i]);

    int64_t t;
    cin >> t;

    while (t --> 0) {
        int64_t n;       
        cin >> n;

        vector<int64_t> x(n << 1);
        for (auto& xi: x)
            cin >> xi;

        int64_t ss = accumulate(x.begin(), x.end(), 0LL);

        if (ss % (n + 1)) {
            cout << 0 << "\n";
        } else {
            int64_t s = ss / (n + 1);

            auto cnt = BuildCounter(x);

            if (!CheckCounterInvariants(cnt, s))
                cout << 0 << "\n";
            else
                cout << CalculateAnswer(cnt, s) << "\n";
        }
    }

    return 0;
}
