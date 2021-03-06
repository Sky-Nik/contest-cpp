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
	cout << size(v) << "\n";  // problem-specific
    for (const auto& e: v) {
        cout << e << " ";
    }
    cout << "\n";
    return os;
}

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
    vector<vector<int>> a(n, vector<int>(n, 0));
    cin >> a;
    vector<int> answer; bool p = true;
    forn(i, n) {
    	p = true;
    	forn(j, n) p &= (a[i][j] != 1 && a[i][j] != 3);
    	if (p) answer.push_back(i + 1);
    }
    cout << answer;
    return 0;
}