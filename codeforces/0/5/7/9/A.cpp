#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define forn(i, n) for(int i = 0; i < n; ++i)

int main() {
    int x;
    cin >> x;
    int answer = 0;
    while (x > 0) {
        answer += x & 1;
        x >>= 1;
    }
    cout << answer;
    return 0;
}