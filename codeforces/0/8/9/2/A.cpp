#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
#define sort(v) sort(begin(v), end(v))
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
    vector<int> a(n), b(n);
    cin >> a >> b;
    sort(b);
    if (sum(a) <= b[n - 1] + b[n - 2]) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
