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
    vector<int> fib{0, 1};
    while (fib[size(fib) - 1] < 1000000000) fib.push_back(fib[size(fib) - 1] + fib[size(fib) - 2]);
    int n;
    cin >> n;
    int ia = -1, ja = -1, ka = -1;
    forn(i, size(fib)) forn(j, size(fib)) forn(k, size(fib)) if (fib[i] + fib[j] + fib[k] == n) tie(ia, ja, ka) = make_tuple(fib[i], fib[j], fib[k]);
    if (ia != -1) {
    	cout << ia << " " << ja << " " << ka;
    } else {
    	cout << "I'm too stupid to solve this problem";
    }
    return 0;
}