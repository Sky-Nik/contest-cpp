#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

#define elif else if
#define forn(_i, _n) for(int _i = 0; _i < _n; ++_i)
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
    vector<string> board(8);
    cin >> board;
    int white = 0, black = 0;
    map<char, int> costs = {
    	{'Q', 9},
    	{'R', 5},
    	{'B', 3},
    	{'N', 3},
    	{'P', 1},
    	{'K', 0},
    	{'.', 0}
    };
    forn(i, 8) forn(j, 8) {
    	if (isupper(board[i][j])) {
    		white += costs[board[i][j]];
    	} else {
    		black += costs[toupper(board[i][j])];
    	}
    }
    if (white > black) {
    	cout << "White";
    } elif (white < black) {
    	cout << "Black";
    } else {
    	cout << "Draw";
    }
    return 0;
}
