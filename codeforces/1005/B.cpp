#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int sl = s.length(), tl = t.length();
    int to_remain = 0;
    for (int i = 0; (s[sl - 1 - i] == t[tl - 1 - i]) && (i < min(sl, tl)); ++i) {
        ++to_remain;
    }
    cout << sl + tl - (to_remain << 1);
    return 0;
}