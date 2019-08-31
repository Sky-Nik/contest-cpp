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
    int m;
    cin >> m;
    vector<int> b(m);
    cin >> b;
    vector<int> f(5001);
    forn(i, m) ++f[b[i]];
    int answer = 0, _max = 0;
    for (int i = 5001; i --> 0;) {
    	answer += (answer ? min(2, f[i]) : min(1, f[i]));
    	if (answer && !_max) _max = i;
    }
    cout << answer << "\n";
    forn(i, 5001) if (f[i]) {
    	cout << i << " ";
    	--f[i];
    }
    for (int i = 5001; i --> 0;) if (i != _max && f[i]) {
    	cout << i << " ";
    	--f[i];
    }
    return 0;
}
