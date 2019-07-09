#include <bits/stdc++.h>
using namespace std;
#define elif else if
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int j = 1 + ((n - 11) >> 1), i = 0;
    for (; j > 0 && i < n; ++i) {
        if (s[i] == '8') {
            --j;
        }
        if (j == 0) {
            break;
        }
    }
    if (j > 0 || i > n - 11) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    //cout << "\ni = " << i << ", j = " << j;
    return 0;
}