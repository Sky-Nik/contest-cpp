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
    string s;
    cin >> s;
    int answer = 0, current;
    forn(i, s.length()) { // K
    	current = 0;
    	fore(j, 1, s.length()) {
    		if (s[j - 1] == 'V' && j == i ||
    			s[j - 1] == 'V' && s[j] == 'K' && j - 1 != i) {
    			++current;
    		}
    	}
    	answer = max(answer, current);
    }
    forn(i, s.length()) { // V
    	current = 0;
    	fore(j, 1, s.length()) {
    		if (j != i && s[j - 1] == 'V' && s[j] == 'K' ||
    			j - 1 == i && s[j] == 'K') {
    			++current;
    		}
    	}
    	answer = max(answer, current);
    }
    cout << answer;
    return 0;
}