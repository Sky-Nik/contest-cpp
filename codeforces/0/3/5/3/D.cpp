#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int j = distance(s.begin(), find(s.begin(), s.end(), 'M'));

    int t = 0, f = j;
    for (int i = j; i < s.length(); ++i) {
        if (s[i] == 'F') {
            t = max(t + 1, i - f);
            ++f;
        }
    }

    cout << t;

    return 0;
}
