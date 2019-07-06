#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int frequencies[26];
    int max_f = 0;
    for (int i = 0; i < 26; ++i) {
        frequencies[i] = 0;
    }
    for (char c: s) {
        ++frequencies[c - 'a'];
        max_f = max(max_f, frequencies[c - 'a']);
    }
    if (max_f <= k) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}