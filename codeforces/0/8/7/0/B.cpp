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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;
    if (k == 1) {
    	cout << *min_element(begin(a), end(a));
    } elif (k == 2) {
    	vector<int> p(n, a[0]), s(n, a[n - 1]);
    	fore(i, 1, n) {
    		p[i] = min(a[i], p[i - 1]);
    	}
    	for (int i = n - 2; i --> 0;) {
    		s[i] = min(s[i + 1], a[i]);
    	}
    	int answer = numeric_limits<int>::min();
    	forn(i, n - 1) {
    		answer = max(answer, max(p[i], s[i + 1]));
    	}
    	cout << answer;
    } else {
    	cout << *max_element(begin(a), end(a));
    }
    return 0;
}
