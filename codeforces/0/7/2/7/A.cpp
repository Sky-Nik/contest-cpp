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
    int a, b;
    cin >> a >> b;
    vector<int> answer;
    bool p = true;
    while (b > a) {
    	answer.push_back(b);
    	if (b & 1) {
    		if (b % 10 == 1) {
    			b /= 10;
    		} else {
    			p = false;
    			break;
    		}
    	} else {
    		b >>= 1;
    	}
    }
    answer.push_back(b);
    p &= b == a;
    if (p) {
    	int k = size(answer);
    	cout << "YES\n" << k << "\n";
    	forn(i, k) cout << answer[k - 1 - i] << " ";
    } else {
    	cout << "NO";
    }
    return 0;
}