#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    for (int i = s.length() - 1; i >= 0; --i) {        
        if (isalpha(s[i])) {
            // cout << "s[" << i << "] = " << s[i] << "\n";
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y' ||
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y') {
                cout << "YES";
            } else {
                cout << "NO";
            }
            return 0;
        }
    }
}