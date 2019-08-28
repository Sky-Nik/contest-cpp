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
    map<char, int> f { 
    	make_pair('B', 1), 
    	make_pair('u', 2), 
    	make_pair('l', 1), 
    	make_pair('b', 1), 
    	make_pair('a', 2), 
    	make_pair('s', 1), 
    	make_pair('r', 1)
    };
    map<char, int> fs { 
    	make_pair('B', 0), 
    	make_pair('u', 0), 
    	make_pair('l', 0), 
    	make_pair('b', 0), 
    	make_pair('a', 0), 
    	make_pair('s', 0), 
    	make_pair('r', 0)
    };
    for (auto c: s) if (fs.find(c) != fs.end()) ++fs[c];
    int answer = numeric_limits<int>::max();
    for (auto [k, v]: f) answer = min(answer, fs[k] / v);
    cout << answer;
    return 0;
}