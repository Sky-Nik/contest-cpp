#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
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
    vector<int> a(n);
    cin >> a;
    a.push_back(0);
    int ans = 1, cur = 1;
    forn(i, n) {
        if (a[i + 1] > a[i]) {
            ++cur;
        } else {
            ans = max(ans, cur);
            cur = 1;
        }
    }
    cout << ans;
    return 0;
}