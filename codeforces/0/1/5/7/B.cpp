#include <bits/stdc++.h>
using namespace std;
# define M_PI           3.14159265358979323846  /* pi */
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ld answer = 0;
    cin >> n;
    vector<int> r(n);
    cin >> r;
    sort(begin(r), end(r), greater<>());
    forn(i, n) {
    	if (i & 1) {
    		answer -= M_PI * r[i] * r[i];
    	} else {
    		answer += M_PI * r[i] * r[i];
    	}
    }
    cout << fixed << setprecision(9) << answer;
    return 0;
}
