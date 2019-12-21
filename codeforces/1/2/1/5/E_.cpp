#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef int64_t ll;

auto cnt_(vector<int>& a, int lc, int rc) {
    ll k=0;
    int rk=0;
    for (auto& ai: a) if (ai==lc) k+=rk; else if (ai==rc) ++rk;
    return k;
}

ll dp_(vector<ll>& dp, vector<vector<ll>>& cnt, int m) {
    if (dp[m]==1LL<<40) {
        for (int lc=0;lc<20;++lc) {
            if ((m>>lc)&1) {
                ll c=dp_(dp,cnt,m-(1<<lc));
                for (int llc=0;llc<20;++llc) if (llc!=lc&&(m>>llc)&1) c+=cnt[llc][lc];
                dp[m]=min(dp[m],c);
            }
        }
    }
    return dp[m];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> a(n);
    for (auto& ai: a) cin>>ai;
    vector<vector<ll>> cnt(20,vector<ll>(20,0));
    for (int lc=0;lc<20;++lc) for (int rc=0;rc<20;++rc) if (lc!=rc) cnt[lc][rc]=cnt_(a,lc+1,rc+1);
    vector<ll> dp(1<<20,1LL<<40);
    dp[0]=0;
    cout<<dp_(dp,cnt,(1<<20)-1);
    return 0;
}
