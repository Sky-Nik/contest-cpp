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

bool lucky(int time) {
	if (time / 600 == 7) {
		return true;
	} else {
		time %= 600;
		if (time / 60 == 7) {
			return true;
		} else {
			time %= 60;
			if (time / 10 == 7) {
				return true;
			} else {
				time %= 10;
				return time == 7;
			}
		}
	}
}

int sub(int time, int x) {
	return (time - x + 24 * 60) % (24 * 60);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, hh, mm, time, answer = 0;
	cin >> x >> hh >> mm;
	time = 60 * hh + mm;
	while (!lucky(time)) {
    	time = sub(time, x);
    	++answer;
    }
    cout << answer;
	return 0;
}
