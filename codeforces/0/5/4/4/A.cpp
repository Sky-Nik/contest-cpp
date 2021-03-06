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
    int k;
    string q;
    cin >> k >> q;
    vector<int> p(26);
    forn(i, 26) p[i] = distance(begin(q), find(begin(q), end(q), static_cast<char>(i + 'a')));
    if (count(begin(p), end(p), q.length()) <= 26 - k) {
    	cout <<"YES\n";
    	sort(begin(p), end(p));
    	forn(i, k - 1) cout << q.substr(p[i], p[i + 1] - p[i]) << "\n";
    	cout << q.substr(p[k - 1], q.length() - p[k - 1]);
    } else {
    	cout <<"NO";
    }
    return 0;
}