#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    char cur = 'a';
    int a = 0;
    for (char c: s) {
        a += min(abs(c - cur), 26 - abs(c - cur));
        cur = c;
    }
    cout << a;
    return 0;
}