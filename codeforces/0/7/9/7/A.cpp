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

// O(sqrt(n)), all factors, with powers
template <typename T>
vector<T> factorize (T n) {
    vector<T> a;
    for (T i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            a.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        a.push_back(n);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> f = factorize(n);
    if (size(f) < k) {
    	cout << -1;
    } else {
    	forn(i, k - 1) cout << f[i] << " ";
    	int p = 1;
    	fore(i, k - 1, size(f)) p *= f[i];
    	cout << p;
    }
    return 0;
}