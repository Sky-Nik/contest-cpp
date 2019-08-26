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

// O(sqrt(n))
template <typename T>
T is_prime (T n) {
	if (n == 1) return false;
    for (T i = 2; i * i <= n; ++i) if (n % i == 0) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    ll a, b;
    cin >> t;
    while (t --> 0) {
    	cin >> a >> b;
    	if (a - b != 1) {
    		cout << "NO\n";
    	} else if (is_prime(a + b)) {
    		cout << "YES\n";
    	} else {
    		cout << "NO\n";
    	}
    }
    return 0;
}