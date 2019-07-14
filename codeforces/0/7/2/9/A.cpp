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
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += "  ";
    int i = 0;
    while (i < n) {
        if (s[i] == 'o' && s[i + 1] == 'g' && s[i + 2] == 'o') {
            cout << "***";
            s[i] = '*';
            s[i + 1] = '*';
            s[i + 2] = '*';
            i += 2;
        } elif (s[i] == '*' && s[i + 1] == 'g' && s[i + 2] == 'o') {
            s[i + 1] = '*';
            s[i + 2] = '*';
            i += 2;
        } elif (s[i] == '*') {
            ++i;
        } else {
            cout << s[i];
            ++i;
        }
    }
    return 0;
}