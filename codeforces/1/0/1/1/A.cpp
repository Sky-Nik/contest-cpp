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
    int n, k;
    cin >> n >> k;
    vector<char> s(n);
    cin >> s;
    sort(begin(s), end(s));
    int i = 1;
    char c = s[0];
    int ans = c - 'a' + 1;
    --k;
    while (k && i < n) {
        while (i < n && s[i] - c < 2) {
            ++i;
        }
        if (i < n) {
            //cout << s[i] << "|";
            ans += s[i] - 'a' + 1;
            --k;
            c = s[i];
            ++i;
        }
    }
    if (!k) {
        cout << ans;
    } else {
        cout << -1;
    }
    return 0;
}