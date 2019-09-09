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
    int n, B, e = 0, o = 0, answer = 0;
    cin >> n >> B;
    vector<int> a(n), possible;
    cin >> a;
    forn(i, n - 1) {
    	if (a[i] & 1) {
    		++o;
    	} else {
    		++e;
    	}
    	if (o == e) {
    		possible.push_back(abs(a[i] - a[i + 1]));
    	}
    }
    sort(begin(possible), end(possible));
    for (auto cost: possible) {
    	if (cost <= B) {
    		B -= cost;
    		++answer;
    	} else {
    		break;
    	}
    }
    cout << answer;
    return 0;
}
