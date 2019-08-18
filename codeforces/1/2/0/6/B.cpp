#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)

int main() {
    int n;
    cin >> n;
    ll negative = 0, zero = 0, positive = 0;
    ll answer = 0;
    forn(i, n) {
        ll ai;
        cin >> ai;
        if (ai < -1) {
            answer += -1 - ai;
        } elif (ai > 1) {
            answer += ai - 1;
        }
        if (ai < 0) {
            ++negative;
        } elif (ai > 0) {
            ++positive;
        } else {
            ++zero;
        }
    }
    if ((negative & 1) && (!zero)) {
        answer += 2;
    } else {
        answer += zero;
    }
    cout << answer;
    return 0;
}