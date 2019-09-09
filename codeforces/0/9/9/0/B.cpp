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
    int n, K, answer = 0, ai;
    cin >> n >> K;
    map<int, int> pre_a;
    forn(i, n) {
    	cin >> ai;
    	if (pre_a.find(ai) == pre_a.end()) {
    		pre_a[ai] = 0;
    	}
    	++pre_a[ai];
    }
    vector<pii> a;
    for (auto kv: pre_a) {
    	a.push_back(kv);
    }
    sort(begin(a), end(a));
    forn(i, a.size() - 1) {
    	if (a[i].first + K < a[i + 1].first) {
    		answer += a[i].second;
    	}
    }
    cout << answer + a[a.size() - 1].second;
    return 0;
}
