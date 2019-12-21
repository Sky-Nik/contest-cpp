#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> a(n);
    for (auto& ai:a) cin >> ai;
    vector<vector<int>> dp(2,{0});
    for (const auto& ai:a) {
        if (ai<0) {
            auto t=dp[0].back();
            dp[0].push_back(dp[1].back()+1);
            dp[1].push_back(t);
        } else {
            dp[1].push_back(dp[1].back()+1);
            dp[0].push_back(dp[0].back());
        }
    }
    cout<<accumulate(dp[0].begin(),dp[0].end(),0LL)<<" "<<accumulate(dp[1].begin(),dp[1].end(),0LL);
    return 0;
}
