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
inline ostream& operator << (ostream& os, const vector<T>& v) {
    for (const auto& e: v) {
        cout << e << " ";
    }
    cout << "\n";
    return os;
}

template<typename U, typename V>
inline istream& operator >> (istream& is, pair<U, V>& p) {
    cin >> p.first >> p.second;
    return is;
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
    map<string, int> m = {
    	{"S", 0},
    	{"M", 1},
    	{"L", 2},
    	{"XL", 3},
    	{"XXL", 4},
    };
    map<int, string> m_inv = {
    	{0, "S"},
    	{1, "M"},
    	{2, "L"},
    	{3, "XL"},
    	{4, "XXL"},
    };
    vector<int> n(5);
    int k, wanted_index, i, j;
    string wanted;
    cin >> n >> k;
    while (k --> 0) {
    	cin >> wanted;
    	wanted_index = m[wanted];
    	i = 0, j = 0;
    	while (wanted_index + i < 0 || wanted_index + i > 4 || !n[wanted_index + i]) {
//    		cout << wanted_index + i << "\n";
    		if (j & 1) {
    			i = -i;
    		} else {
    			i = 1 - i;
    		}
    		++j;
    	}
    	--n[wanted_index + i];
    	cout << m_inv[wanted_index + i] << "\n";
    }
    return 0;
}
