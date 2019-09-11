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
	os << v.size() << "\n";
    for (const auto& e: v) {
        os << e << "\n";
    }
    return os;
}

int s(int x) {
	int a = 0;
	while (x) {
		a += x % 10;
		x /= 10;
	}
	return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    vector<int> answer;
    cin >> n;
    fore(k, max(1, n - 100), n) {
    	if (s(k) + k == n) {
    		answer.push_back(k);
    	}
    }
    cout << answer;
    return 0;
}
