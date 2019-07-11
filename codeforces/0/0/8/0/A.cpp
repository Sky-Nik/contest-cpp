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

template<typename T>
vector<bool> prime_sieve(T n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (size_t i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (T j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<bool> is_prime = prime_sieve(m);
    bool the_end_is_near = true;
    fore(i, n + 1, m - 1) {
        if (is_prime[i]) {
            the_end_is_near = false;
        }
    }
    if (!is_prime[m]) {
        the_end_is_near = false;
    }
    if (the_end_is_near) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}