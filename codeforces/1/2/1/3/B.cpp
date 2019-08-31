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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n, m, answer;
    cin >> t;
    while (t --> 0) {
    	m = numeric_limits<int>::max();
    	answer = 0;
		cin >> n;
		vector<int> a(n);
		cin >> a;
		for (int i = n; i --> 0;) {
			if (a[i] > m) {
				++answer;
			} else {
				m = a[i];
			}
		}
		cout << answer << "\n";
    }
    return 0;
}
