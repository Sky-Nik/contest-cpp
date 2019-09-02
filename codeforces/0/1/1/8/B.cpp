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
inline ostream& operator << (ostream& os, const vector<T>& v) {
    for (const auto& e: v) {
        cout << e << " ";
    }
    cout << "\n";
    return os;
}

template<typename U, typename V>
inline istream& operator >> (istream& is, pair<U, V>& p) {
    cin >> p.first >> p.second;
    return is;
}

template<typename T>
inline istream& operator >> (istream& is, vector<T>& v) {
    for (auto& e: v) {
        cin >> e;
    }
    return is;
}

std::string& trim(std::string& s, const char* t = " \t\n\r\f\v") {
    //s.erase(0, s.find_first_not_of(t));
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n;
    vector<vector<char>> board(2 * n + 1, vector<char>(2 * n + 1, ' '));
    forn(i, 2 * n + 1) {
    	forn(j, 2 * n + 1) {
    		k = n - abs(i - n) - abs(j - n);
    		if (k >= 0) board[i][j] = static_cast<char>('0' + k);
    	}
    }
    forn(i, 2 * n + 1) {
        string s = "";
		forn(j, 2 * n + 1) {
			s += board[i][j];
            s += " ";
		}
        trim(s);
		cout << s << "\n";
	}
    return 0;
}
