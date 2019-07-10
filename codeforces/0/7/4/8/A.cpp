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
    int n, m, k;
    cin >> n >> m >> k;
    --k;
    cout << (k / (m << 1)) + 1 << " ";
    k %= (m << 1);
    cout << k / 2 + 1 << " ";
    if (k & 1) {
        cout << "R";
    } else {
        cout << "L";
    }
    return 0;
}