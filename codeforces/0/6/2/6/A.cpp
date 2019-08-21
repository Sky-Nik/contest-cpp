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
    char c;
    cin >> n;
    vector<vector<int>> pxy(2, vector<int>(n + 1, 0));
    forn(i, n) {
    	cin >> c;
    	if (c == 'L') tie(pxy[0][i + 1], pxy[1][i + 1]) = make_pair(pxy[0][i] - 1, pxy[1][i]);
    	if (c == 'R') tie(pxy[0][i + 1], pxy[1][i + 1]) = make_pair(pxy[0][i] + 1, pxy[1][i]);
    	if (c == 'U') tie(pxy[0][i + 1], pxy[1][i + 1]) = make_pair(pxy[0][i], pxy[1][i] + 1);
    	if (c == 'D') tie(pxy[0][i + 1], pxy[1][i + 1]) = make_pair(pxy[0][i], pxy[1][i] - 1);
    }
    int answer = 0;
    forn(l, n) fore(r, l, n) if (pxy[0][r + 1] == pxy[0][l] && pxy[1][r + 1] == pxy[1][l]) ++ answer;
    cout << answer;
    return 0;
}