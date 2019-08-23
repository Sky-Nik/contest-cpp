#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

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
    int x = 0, X = 0;
    forn(i, n) ((s[i] == 'x') ? (++x) : (++X));
    int answer = (x - X) >> 1;
    cout << abs(answer) << "\n";
    if (answer < 0) forn(i, n) if (answer < 0 && s[i] == 'X') { s[i] = 'x'; ++answer; }
    if (answer > 0) forn(i, n) if (answer > 0 && s[i] == 'x') { s[i] = 'X'; --answer; }
    cout <<	s;
    return 0;
}