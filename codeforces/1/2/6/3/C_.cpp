#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,n;
    cin>>t;
    while (t-->0) {
        cin>>n;
        vector<int> a,b;
        for (int i=0;i*i<=n;++i) a.push_back(i);
        for (int i=1;i*i<=n;++i) b.push_back(n/i);
        reverse(b.begin(), b.end());
        for (auto& bi: b) if (bi!=a.back()) a.push_back(bi);
        cout<<a.size()<<"\n";
        for (auto& ai: a) cout<<ai<<" ";
        cout<<"\n";
    }
    return 0;
}
