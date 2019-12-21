#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s,t;
    cin>>n>>s>>t;
    vector<vector<int>> p(2);
    for (int i=0;i<n;++i) {
        if (s[i]=='a'&&t[i]=='b') p[0].push_back(i+1);
        if (s[i]=='b'&&t[i]=='a') p[1].push_back(i+1);
    }
    if ((p[1].size()+p[0].size())&1) {
        cout<<-1;
    } else {
        cout<<(((p[0].size()+1)>>1)+((p[1].size()+1)>>1))<<"\n";
        for (int i=0;i+1<p[1].size();i+=2) cout<<p[1][i]<<" "<<p[1][i+1]<<"\n";
        for (int i=0;i+1<p[0].size();i+=2) cout<<p[0][i]<<" "<<p[0][i+1]<<"\n";
        if (p[0].size()&1) {
            cout<<p[0].back()<<" "<<p[0].back()<<"\n";
            cout<<p[0].back()<<" "<<p[1].back();
        }
    }
    return 0;
}
