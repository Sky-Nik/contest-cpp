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
    int q;
    cin >> q;
    map<string, string> m;
    bool f;
    string o, n;
    while (q --> 0) {
    	cin >> o >> n;
  		f = false;
    	for (auto& kv: m) if (kv.second == o) {
    		kv.second = n;
			f = true;
		}
		if (!f) m[o] = n;
    }
    cout << m.size() << "\n";
    for(auto kv: m) {
    	cout << kv.first << " " << kv.second << "\n";
    }
    return 0;
}
