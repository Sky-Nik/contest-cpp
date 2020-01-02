#include <bits/stdc++.h>
using namespace std;

int intersection(int l1, int r1, int l2, int r2) {
    return max(0,min(r1,r2)-max(l1,l2));
}

int main() {
    int t,a,b,c,r;
    cin>>t;
    while (t-->0) {
        cin>>a>>b>>c>>r;
        cout<<abs(b-a)-intersection(min(a,b),max(a,b),c-r,c+r)<<"\n";
    }
    return 0;
}
