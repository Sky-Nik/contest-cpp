#include <bits/stdc++.h>
using namespace std;

int64_t calculate_answer(vector<string>& ws, vector<int>& is, int d) {
    int64_t answer = 0, k = 0;

    vector<vector<int>> partition(26 * 26);
    for (auto i: is) {
        if (ws[i].length() > d)
            partition[
                ws[i][d] - 'a' + 26 * (ws[i][ws[i].length() - 1 - d] - 'a')
            ].push_back(i);
        else
            ++k;
    }

    for (auto part: partition) {
        if (part.size() > 1)
            answer += calculate_answer(ws, part, d + 1);

        if (part.size() & 1)
            ++k;
    }

    return answer + (k >> 1) * d * d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --> 0) {
        int n;
        cin >> n;

        vector<string> ws(n);
        for (auto& wi: ws)
            cin >> wi;

        vector<int> is(n);
        for (int i = 0; i < n; ++i)
            is[i] = i;

        cout << calculate_answer(ws, is, 0) << "\n";
    }

    return 0;
}
