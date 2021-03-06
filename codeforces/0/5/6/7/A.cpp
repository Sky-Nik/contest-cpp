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
    vector<int> x(n);
    cin >> x;
    forn(i, n) {
    	cout << min(abs(x[i] - x[i ? i - 1 : i + 1]), abs(x[i + 1 == n ? i - 1 : i + 1] - x[i]))
    		<< " " << max(x[i] - x[0], x[n - 1] - x[i]) << "\n";
    }
    return 0;
}