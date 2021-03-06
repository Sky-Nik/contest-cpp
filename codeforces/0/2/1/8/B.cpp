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
    int n, m, ai, answer_1 = 0, answer_2 = 0;
    cin >> n >> m;
    priority_queue<int> a1, a2;
    forn(i, m) {
    	cin >> ai;
    	a1.push(ai);
    	a2.push(-ai);
    }
	forn(i, n) {
		ai = a1.top();
		answer_1 += ai;
		a1.pop();
		if (ai != 1) {
			a1.push(ai - 1);
		}
		ai = a2.top();
		answer_2 -= ai;
		a2.pop();
		if (ai != -1) {
			a2.push(ai + 1);
		}
	}
	cout << answer_1 << " " << answer_2;
    return 0;
}
