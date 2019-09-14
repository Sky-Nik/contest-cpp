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
        is >> e;
    }
    return is;
}

template<typename T>
inline ostream& operator << (ostream& os, const vector<T>& v) {
    for (const auto& e: v) {
        os << e << " ";
    }
    os << "\n";
    return os;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> f(101, 0), p(101, 0);
    string s;
    forn(i, n) {
    	cin >> s;
    	++f[s.length()];
    }
    forn(i, 100) {
    	p[i + 1] = p[i] + f[i + 1];
    }
    cin >> s;
    int answer1 = 0, answer2 = 0;
    answer1 = p[s.length() - 1] + 1;
    answer2 = p[s.length()];
    cout << answer1 + 5 * ((answer1 - 1) / k) << " " << answer2 + 5 * ((answer2 - 1) / k);
    return 0;
}
