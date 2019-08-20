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
    bool p = true;
    while (n > 0) {
    	if (n % 10 == 1) {
    		n /= 10;
    	} elif (n % 100 == 14) {
    		n /= 100;
    	} elif (n % 1000 == 144) {
    		n /= 1000;
    	} else {
    		p = false;
    		break;
    	}
    }
    if (p) {
    	cout << "YES";
    } else {
    	cout << "NO";
    }
    return 0;
}