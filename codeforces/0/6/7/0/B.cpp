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

/* Binary search to find 
 * the smallest value of x 
 * with checker(x) true.
 * Typename T should model
 * totally ordered discrete set. */
template <typename T>
T binary_search_z(T lower_bound, T upper_bound, bool(*checker) (T)) {
    T middle;
    while (lower_bound < upper_bound) {
        middle = (lower_bound + upper_bound) >> 1;
        if ((*checker)(middle)) {
            upper_bound = middle;
        } else {
            lower_bound = middle + 1;
        }
    }
    return lower_bound;
}

template<typename T>
inline istream& operator >> (istream& is, vector<T>& v) {
    for (auto& e: v) {
        cin >> e;
    }
    return is;
}

ll k;

bool checker(ll l) {
	return (l + 2) * (l + 1) / 2 >= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, l;
    cin >> n >> k;
    std::vector<ll> a(n);
    cin >> a;
    l = binary_search_z(0ll, n, checker);
    cout << a[k - (l + 1) * l / 2 - 1];
    return 0;
}