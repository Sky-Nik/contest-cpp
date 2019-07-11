#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, l, r) for(int i = l; i < r; ++i)
#define sum(a) accumulate(begin(a), end(a), 0ll)

template<typename T>
inline istream& operator >> (istream& is, vector<T>& v) {
    for (auto& e: v) {
        cin >> e;
    }
    return is;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.length();
    bool is_palindrome = true, is_constant = true;
    forn(i, n) {
        if (s[i] != s[n - 1 - i]) {
            is_palindrome = false;
        }
        if (s[i] != s[0]) {
            is_constant = false;
        }
    }
    if (!is_palindrome) {
        cout << n;
    } elif (is_constant) {
        cout << 0;
    } else {
        cout << n - 1;
    }
    return 0;
}