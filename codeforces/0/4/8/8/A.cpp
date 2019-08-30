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

bool lucky(int a) {
	if (a < 0) a = -a;
	while (a != 0) {
		if (a % 10 == 8) return true;
		a /= 10;
	}
	return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b = 1;
    cin >> a;
    ++a;
    while (!lucky(a)) {
    	++a;
    	++b;
    }
    cout << b;
    return 0;
}