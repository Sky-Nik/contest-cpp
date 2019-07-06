#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll a = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0' || s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '8') {
            a += (i + 1);
        }
    }
    cout << a;
    return 0;
}