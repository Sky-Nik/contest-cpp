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

int gcd_steps(int a, int b) {
	int c = 0;
	while (b != 0) {
		tie(a, b, c) = make_tuple(b, a % b, c + a / b);
	}
	return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ai, bi;
    cin >> n;
    while (n --> 0) {
        cin >> ai >> bi;
        cout << gcd_steps(ai, bi) << "\n";
    }
    return 0;
}
