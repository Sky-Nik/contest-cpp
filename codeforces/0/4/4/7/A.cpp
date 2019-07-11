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
    int p, n;
    cin >> p >> n;
    vector<int> x(n);
    vector<int> hash(p, -1);
    cin >> x;
    forn(i, n) {
        if (hash[x[i] % p] != -1) {
            cout << i + 1;
            return 0;
        }
        hash[x[i] % p] = x[i];
    }
    cout << -1;
    return 0;
}