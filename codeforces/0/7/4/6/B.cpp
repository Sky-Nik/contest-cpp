#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
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
    vector<char> t(n);
    if (n & 1) {
        t[n >> 1] = s[0];
        int i = (n >> 1) - 1, j = (n >> 1) + 1;
        for (int k = 1; k < n; ++k) {
            if (k & 1) {
                t[i--] = s[k];
            } else {
                t[j++] = s[k];
            }
        }
    } else {
        int i = (n >> 1) - 1, j = (n >> 1);
        for (int k = 0; k < n; ++k) {
            if (k & 1) {
                t[j++] = s[k];
            } else {
                t[i--] = s[k];
            }
        }
    }
    for (char c: t) {
        cout << c;
    }
    return 0;
}