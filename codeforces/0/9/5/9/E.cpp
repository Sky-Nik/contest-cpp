#include <bits/stdc++.h>
using namespace std;

int64_t f(int64_t n) {
    if (n == 2)
        return 1;

    if (n == 3)
        return 3;

    if (n & 1)
        return (f((n >> 1) + 1) << 1) + (n >> 1);
    
    return (f(n >> 1) << 1) + (n >> 1);
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n;
    cin >> n;

    cout << f(n);

    return 0;
}
