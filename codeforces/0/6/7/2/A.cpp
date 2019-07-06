#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s = "";
    for (int i = 1; i < 400; ++i) {
        s += to_string(i);
    }
    cout << s[n - 1];
    return 0;
}