#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> ans(n, 0);
    for (int i = 0, ai; i < a; ++i) {
        cin >> ai;
        ans[ai - 1] = 1;
    }
    for (int i = 0, ai; i < b; ++i) {
        cin >> ai;
        ans[ai - 1] = 2;
    }
    for (int ai: ans) {
        cout << ai << " ";
    }
    return 0;
}