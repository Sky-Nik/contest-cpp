#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int>& a, int p, int k, int m) {
    int i=m-1;
    while (i>=k-1) {
        p-=a[i];
        i-=k;
    }
    while (i>=0) {
        p-=a[i];
        --i;
    }
    return p>=0;
}

int binary_search(vector<int>& a, int p, int k) {
    int l=0,r=a.size()+1;
    while (l+1!=r) {
        int m=(l+r)/2;
        if (possible(a, p, k, m)) l=m; else r=m;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,n,p,k;
    vector<int> a;
    cin>>t;
    while (t-->0) {
        cin>>n>>p>>k;
        a.resize(n);
        for (auto& ai:a) cin>>ai;
        sort(a.begin(),a.end());
        cout<<binary_search(a,p,k)<<"\n";
    }
    return 0;
}
