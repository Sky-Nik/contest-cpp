#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    int i = 0;
    for (int j = 0; j < t.length(); ++j) {
        if (s[i] == t[j]) {
            ++i;
        }
    }
    cout << i + 1;
    return 0;
}