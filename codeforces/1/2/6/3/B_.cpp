#include <bits/stdc++.h>
using namespace std;
#define forn(_1,_2) for(int _1=0;_1<_2;++_1)
#define fore(_1,_2,_3) for(int _1=_2;_1<_3;++_1)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n, k;
    vector<string> p, ap;
    cin >> t;
    while (t-->0) {
        cin>>n;
        p.resize(n);
        for (auto& pi: p) cin>>pi;
        k=0;
        ap=p;
        forn(i,n) {
            fore(j,i+1,n) {
                if (ap[i]==ap[j]) {
                    ++k;
                    bool fk=false;
                    forn(k,4) {
                        bool fd;
                        forn(d,10) {
                            fd=true;
                            ap[i][k]=d+'0';
                            forn(l,n) fd&=((i==l)||(ap[i]!=ap[l]));
                            if (fd) break; else ap[i][k]=p[i][k];
                        }
                        fk|=fd;
                        if (fk) break;
                    }
                }
            }
        }
        cout<<k<<"\n";
        for (auto pi: ap) cout<<pi<<"\n";
    }
    return 0;
}
