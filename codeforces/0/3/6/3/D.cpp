#include <bits/stdc++.h>
using namespace std;

bool possible(const vector<int64_t>& b, const vector<int64_t>& p, int64_t n, int64_t m, int64_t a,
    int64_t middle) {
    for (int64_t i = 0; i < middle; ++i)
        a -= max(0LL, p[i] - b[n - middle + i]);

    return a >= 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n, m, a;
    cin >> n >> m >> a;
    vector<int64_t> b(n), p(m);
    for (auto& bi: b)
        cin >> bi;
    for (auto& pi: p)
        cin >> pi;

    sort(b.begin(), b.end());
    sort(p.begin(), p.end());

    int64_t lower = 0, middle, upper = min(n, m) + 1;
    
    while (lower + 1 != upper) {
        middle = (lower + upper) >> 1;
        if (possible(b, p, n, m, a, middle))
            lower = middle;
        else
            upper = middle;
    }

    int64_t answer = 0;
    for (int i = 0; i < lower; ++i)
        answer += p[i];

    cout << lower << " " << max(0LL, answer - a);

    return 0;
}
