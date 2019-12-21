#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int a1,a2,k1,k2,n;
    cin>>a1>>a2>>k1>>k2>>n;
    int l1=min(a1,n/k1),l2=min(a2,n/k2);
    cout<<max(n-a1*(k1-1)-a2*(k2-1),0)<<" "<<max(l1+min(a2,(n-l1*k1)/k2),l2+min(a1,(n-l2*k2)/k1));
    return 0;
}
