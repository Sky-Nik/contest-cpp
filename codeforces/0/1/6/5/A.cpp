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

inline istream& operator >> (istream& is, pii& p) {
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, answer = 0;
    cin >> n;
    vector<pii> xy(n);
    cin >> xy;
    vector<bool> u(4 * n, false); // fsFS
    forn(i, n) forn(j, n) {
    	if (xy[i].first == xy[j].first &&
    		xy[i].second > xy[j].second) {
    		u[4 * i + 3] = true;
    		u[4 * j + 1] = true;
    	} elif (xy[i].first > xy[j].first &&
    		xy[i].second == xy[j].second) {
    		u[4 * i + 2] = true;
    		u[4 * j + 0] = true;
    	}
    }
    forn(i, n) answer += u[4 * i + 0] && u[4 * i + 1] && u[4 * i + 2] && u[4 * i + 3];
    cout << answer;
    return 0;
}
