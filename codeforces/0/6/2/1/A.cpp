#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, l, r) for(int i = l; i < r; ++i)
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
    int n;
    cin >> n;
    ll answer = 0; int min_odd = numeric_limits<int>::max(), odd_count = 0;;
    forn(i, n) {
    	int ai;
    	cin >> ai;
    	answer += ai;
    	if (ai & 1) {
    		++odd_count;
    		if (ai < min_odd)
    			min_odd = ai;
    	}
    }
    if (odd_count & 1)
    	answer -= min_odd;
    cout << answer;
    return 0;
}