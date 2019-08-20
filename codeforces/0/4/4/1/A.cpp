#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, l, r) for(int i = l; i < r; ++i)
#define sum(a) accumulate(begin(a), end(a), 0ll)

template<typename T>
inline ostream& operator << (ostream& os, const vector<T>& v) {
	cout << size(v) << "\n"; // problem-specific part
    for (const auto& e: v) {
        cout << e << " ";
    }
    cout << "\n";
    return os;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, v, ki, sij; bool p; vector<int> a;
    cin >> n >> v;
    forn(i, n) {
    	cin >> ki;
    	p = false;
    	forn(j, ki) {
    		cin >> sij;
    		p |= sij < v;
    	}
    	if (p) a.push_back(i + 1);
    }
    cout << a;
    return 0;
}