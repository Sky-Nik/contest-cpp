#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,r,g,b; cin>>t;
    while (t-->0) { cin>>r>>g>>b; cout<<min(min(r+g,g+b),min(b+r,(r+g+b)/2))<<"\n"; }
    return 0;
}
