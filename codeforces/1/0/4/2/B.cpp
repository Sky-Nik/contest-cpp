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
    int n, ci, answer = 300001, a = 300001, b = 300001, c = 300001,
    	ab = 300001, ac = 300001, bc = 300001, abc = 300001;
    cin >> n;
    string si;
    while (n --> 0) {
    	cin >> ci >> si;
    	sort(begin(si), end(si));
    	if (si == "A") {
    		a = min(a, ci);
    	} elif (si == "B") {
    		b = min(b, ci);
    	} elif (si == "C") {
    		c = min(c, ci);
    	} elif (si == "AB") {
    		a = min(a, ci);
    		b = min(b, ci);
    		ab = min(ab, ci);
    	} elif (si == "AC") {
    		a = min(a, ci);
    		c = min(c, ci);
    		ac = min(ac, ci);
    	} elif (si == "BC") {
    		b = min(b, ci);
    		c = min(c, ci);
    		bc = min(bc, ci);
    	} elif (si == "ABC") {
    		abc = min(abc, ci);
    	}
    }
    answer = min(answer, abc);
    answer = min(answer, ab + c);
    answer = min(answer, ac + b);
    answer = min(answer, bc + a);
    answer = min(answer, ab + bc);
    answer = min(answer, ab + ac);
    answer = min(answer, bc + ac);
    answer = min(answer, a + b + c);
    if (answer == 300001) {
    	cout << -1;
    } else {
    	cout << answer;
    }
    return 0;
}
