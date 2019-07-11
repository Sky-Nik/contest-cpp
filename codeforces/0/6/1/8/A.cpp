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
    vector<int> d;
    while (n > 0) {
        d.push_back(n & 1);
        n >>= 1;
    }
    for (int i = d.size() - 1; i >= 0; --i) {
        if (d[i] == 1) {
            cout << i + 1 << " ";
        }
    }
    return 0;
}