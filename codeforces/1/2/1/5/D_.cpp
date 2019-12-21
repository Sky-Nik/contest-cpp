#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin>>n>>s;
    int ls=0,rs=0,lf=0,rf=0;
    for (int i=0;i<(n>>1);++i) if (s[i]=='?') ++lf; else ls+=s[i]-'0';
    for (int i=n>>1;i<n;++i) if (s[i]=='?') ++rf; else rs+=s[i]-'0';
    if (ls+9*(lf>>1)==rs+9*(rf>>1)) cout<<"Bicarp"; else cout<<"Monocarp";
    return 0;
}
