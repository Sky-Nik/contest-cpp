#include <bits/stdc++.h>
using namespace std;
#define elif else if
typedef long long ll;

template<typename T>
inline istream& operator >> (istream& is, vector<T>& v) {
    for (auto& e: v) {
        cin >> e;
    }
    return is;
}

template<typename T>
T gcd(T a, T b) {
    T t;
    while (a != 0) {
        t = a;
        a = b % a;
        b = t;
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), p(m);
    cin >> x >> p;
    vector<ll> d(n - 1);
    for (int i = 0; i + 1 < n; ++i) {
        d[i] = x[i + 1] - x[i];
    }
    ll g = 0;
    for (auto di: d) {
        g = gcd(g, di);
    }
    int j = -1;
    for (int i = 0; i < m; ++i) {
        if (g % p[i] == 0) {
            j = i;
        }
    }
    if (j != -1) {
        cout << "YES\n" << x[0] << " " << j + 1;
    } else {
        cout << "NO";
    }
    return 0;
}