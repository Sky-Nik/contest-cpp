#include <bits/stdc++.h>
using namespace std;
long long f(int a) {
    if (a == 0)
        return 1;
    return a * f(a - 1);
}
 
int main() {
    int A, b;
    cin >> A >> b;
    cout << f(min(A,b));
    return 0;
}