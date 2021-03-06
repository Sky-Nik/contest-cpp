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
    string s;
    cin >> s;
    set<char> l;
    int z = 0;
    forn(i, s.length()) {
    	if (s[i] == '?') {
    		++z;
    	} elif (isalpha(s[i])) {
    		l.insert(s[i]);
    	}
    }
    int a = 1, k = 10, ls = l.size();
    if (s[0] == '?') {
    	a = 9;
    	--z;
    } elif (isalpha(s[0])) {
    	a = 9;
    	--ls;
    	--k;
    }
    forn(i, ls) a *= k--;
    string answer = to_string(a);
    forn(i, z) answer += '0';
    cout << answer;
    return 0;
}
