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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(k);
    cin >> a;
    size_t answer_index = 0; ll answer_quantity = 0;
    forn(i, k) if ((n / a[i]) * a[i] > answer_quantity) {
    	answer_quantity = (n / a[i]) * a[i];
    	answer_index = i;
    }
    cout << answer_index + 1 << " " << answer_quantity / a[answer_index] << "\n";
    return 0;
}