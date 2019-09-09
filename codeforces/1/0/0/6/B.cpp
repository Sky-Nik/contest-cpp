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
    int n, k;
    cin >> n >> k;
    vector<pii> a(n);
    forn(i, n) {
    	cin >> a[i].first;
    	a[i].second = i;
    }
    sort(begin(a), end(a), greater<>());
    vector<int> pre_answer(k), answer(k);
	int s_answer = 0;
	forn(i, k) {
		pre_answer[i] = a[i].second + 1;
		s_answer += a[i].first;
	}
	if (k == 1) {
		cout << s_answer << "\n" << n;
    } else {
		sort(begin(pre_answer), end(pre_answer));
		answer[0] = pre_answer[0];
		fore(i, 1, k - 1) {
			answer[i] = pre_answer[i] - pre_answer[i - 1];
		}
		answer[k - 1] = n - pre_answer[k - 2];
		cout << s_answer << "\n" << answer;
    }
    return 0;
}
