#include <bits/stdc++.h>
using namespace std;

int64_t calc(int64_t n, const vector<int64_t>& ks, int64_t di) {
    int cnt = 0;
    for (auto ki: ks)
        cnt += !(ki % di) && ki <= n;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n, m, k;
    cin >> n >> m >> k;
    vector<int64_t> d(m);
    for (auto& di: d)
        cin >> di;
    vector<int64_t> ks(k);
    for (auto& ki: ks)
        cin >> ki;

    vector<int64_t> answer;
    int64_t best = k + 1;
    for (int64_t i = 0; i < m; ++i) {
        int64_t cur = calc(n, ks, d[i]);
        if (cur < best) {
            best = cur;
            answer.clear();
        }

        if (cur == best) {
            answer.push_back(i + 1);
        }
    }

    cout << answer.size() << "\n";
    for (auto ai: answer)
        cout << ai << " ";

    return 0;
}
