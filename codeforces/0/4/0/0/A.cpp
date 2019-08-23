#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, l, r) for(int i = l; i < r; ++i)
#define sum(a) accumulate(begin(a), end(a), 0ll)

template<typename T>
inline ostream& operator << (ostream& os, const vector<T>& v) {
    cout << size(v) << " "; // problem-specific
    for (const auto& e: v) {
        cout << e << "x" << 12 / e << " "; // problem-specific
    }
    cout << "\n";
    return os;
}

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
    int t;
    cin >> t;
    string s;
    while (t --> 0) {
    	cin >> s;
    	vector<int> a;
    	int bi;
    	bool k, ki;
    	for (auto ai: {1, 2, 3, 4, 6, 12}) {
    		bi = 12 / ai;
    		k = false;
    		forn(j, bi) {
    			ki = true;
    			forn(i, ai) ki &= (s[i * bi + j] == 'X');
    			k |= ki;
    		}
    		if (k) a.push_back(ai);
    	}
    	cout << a;
    }
    return 0;
}