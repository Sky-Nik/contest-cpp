#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int count_in(char c, string& s) {
    int a = 0;
    for (char si: s) {
        if (c == si) {
            ++a;
        }
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int a = 0;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (count_in('4', s) + count_in('7', s) <= k) {
            ++a;
        }
    }
    cout << a;
    return 0;
}