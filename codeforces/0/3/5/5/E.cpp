#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& ai: a) cin >> ai;

    int m = *min_element(a.begin(), a.end()),
        M = *max_element(a.begin(), a.end());

    const int kMaxA = 2'000'001;
    vector<int> ppcnt(kMaxA, 0), pcnt(kMaxA + 1, 0);
    for (auto ai: a) ++ppcnt[ai];
    for (int i = 0; i < kMaxA; ++i) pcnt[i + 1] = pcnt[i] + ppcnt[i];

    if (m <= k + 1) {
        cout << m;
    } else {
        int answer = k + 1;
        for (int d = k + 1; d <= m; ++d) {
            int acc = 0;
            for (int i = 1; i <= M / d; ++i) {
                acc += pcnt[i * d + k + 1] - pcnt[i * d];
            }
            if (acc == n) {
                answer = d;
            }
        }
        cout << answer;
    }

    return 0;
}
