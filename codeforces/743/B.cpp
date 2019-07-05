#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll k;

int answer(int n, ll k) {
    ll middle = (1ll << (n - 1));
    if (k < middle) {
        return answer(n - 1, k);
    } else if (k == middle) {
        return n;
    } else {
        return answer(n - 1, k - middle);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    cout << answer(n, k);
    return 0;
}
