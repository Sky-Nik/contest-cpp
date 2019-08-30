#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

#define elif else if
#define forn(_i, _n) for(int _i = 0; _i < static_cast<int>(_n); ++_i)
#define fore(_i, _l, _r) for(int _i = _l; _i < _r; ++_i)
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
    vector<string> board(n);
    cin >> board;
    bool p = true;
    forn(i, n) p &= (board[i][i] == board[0][0]);
    forn(i, n) p &= (board[i][n - 1 - i] == board[0][0]);
    forn(i, n) forn(j, n) if (i != j && i + j != n - 1) p &= (board[i][j] == board[0][1]);
    p &= (board[0][1] != board[0][0]);
    if (p) {
    	cout << "YES";
    } else {
    	cout << "NO";
    }
    return 0;
}
