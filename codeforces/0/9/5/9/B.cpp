#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m;
    cin >> n >> k >> m;

    vector<string> words(n);
    for (auto& word: words)
        cin >> word;

    vector<int64_t> costs(n);
    for (auto& cost: costs)
        cin >> cost;

    map<string, int64_t> d;
    for (int i = 0; i < n; ++i)
        d[words[i]] = costs[i];

    while (k --> 0) {
        int x;
        cin >> x;

        vector<int> synonyms_indices(x);
        for (auto& synonym_index: synonyms_indices)
            cin >> synonym_index;

        int64_t min_cost = numeric_limits<int64_t>::max();
    
        for (auto synonym_index: synonyms_indices)
            min_cost = min(min_cost, d[words[synonym_index - 1]]);

        for (auto synonym_index: synonyms_indices)
            d[words[synonym_index - 1]] = min_cost;
    }

    int64_t ans = 0;

    while (m --> 0) {
        string word;
        cin >> word;
    
        ans += d[word];
    }

    cout << ans;

    return 0;
}