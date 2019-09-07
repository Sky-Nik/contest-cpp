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
    int n, answer = 0, current, i, j;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    sort(begin(a), end(a));
    fore(s, a[0] + a[1], a[n - 1] + a[n - 2] + 1) {
    	i = 0;
    	j = n - 1;
    	current = 0;
    	while (i < j) {
    		if (a[i] + a[j] == s) {
    			++current;
    			++i;
    			--j;
    		} elif (a[i] + a[j] < s) {
    			++i;
    		} else {
    			--j;
    		}
    	}
    	answer = max(answer, current);
    }
    cout << answer;
    return 0;
}
