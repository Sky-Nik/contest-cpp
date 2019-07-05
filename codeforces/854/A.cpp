#include <bits/stdc++.h>
using namespace std;

template<typename T>
T gcd(T a, T b) {
    while (a != 0) {
        T tmp = a;
        a = b % a;
        b = tmp;
    }
    return b;
}

int main() {
    int n;
    cin >> n;
    for (int a = n - 1; a > 0; --a) {
        int b = n - a;
        if ((a < b) && gcd(a, b) == 1) {
            cout << a << " " << b;
            return 0;
        }
    }
}