#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int cl = count(s.begin(), s.end(), 'L'),
        cr = count(s.begin(), s.end(), 'R');

    cout << cl + cr + 1;

    return 0;
}