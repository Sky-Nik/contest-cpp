#include <bits/stdc++.h>
using namespace std;
#define elif else if
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    s += "n";
    bool berland = true;
    for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && 
            s[i] != 'o' && s[i] != 'u' && s[i] != 'n') {
            if (s[i + 1] != 'a' && s[i + 1] != 'e' && s[i + 1] != 'i' && 
                s[i + 1] != 'o' && s[i + 1] != 'u') {
                berland = false;
            }
        }
    }
    if (berland) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
