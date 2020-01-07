#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string wanted = "<3";
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        wanted += word + "<3";
    }
    string actual;
    cin >> actual;

    int j = 0;
    for (int i = 0; i < actual.length() && j < wanted.length(); ++i) {
        if (actual[i] == wanted[j]) {
            ++j;
        }
    }

    if (j == wanted.length()) {
        cout << "yes";
    } else {
        cout << "no";
    }

    return 0;
}
