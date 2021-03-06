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
        is >> e;
    }
    return is;
}

template<typename T>
inline ostream& operator << (ostream& os, const vector<T>& v) {
    for (const auto& e: v) {
        os << e << " ";
    }
    os << "\n";
    return os;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, answer = 0, current, j;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    forn(i, n) {
    	j = i;
    	current = 0;
    	while (j < n && current + a[j] <= 180) {
    		current += a[j];
    		++j;
    	}
    	if (j < n && abs(current + a[j] - 180) < abs(current - 180)) {
    		current += a[j];
    	}
    	if (abs(answer - 180) > abs(current - 180)) {
    		answer = current;
    	}
    }
    cout << 2 * abs(answer - 180);
    return 0;
}
