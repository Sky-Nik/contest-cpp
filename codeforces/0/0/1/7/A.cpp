#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

#define elif else if
#define forn(_i, _n) for(int _i = 0; _i < static_cast<int>(_n); ++_i)
#define fore(_i, _l, _r) for(int _i = _l; _i < _r; ++_i)
#define sum(a) accumulate(begin(a), end(a), 0ll)

template<typename U, typename V>
inline istream& operator >> (istream& is, pair<U, V>& p) {
    is >> p.first >> p.second;
    return is;
}

template<typename U, typename V>
inline ostream& operator << (ostream& os, pair<U, V>& p) {
    os <<  p.first << " " << p.second;
    os << "\n";
    return os;
}

template<typename T>
inline istream& operator >> (istream& is, vector<T>& v) {
    for (auto& e: v) {
        is >> e;
    }
    return is;
}

template<typename T>
inline ostream& operator << (ostream& os, const vector<T>& v) {
    for (const auto& e: v) {
        os << e << " ";
    }
    os << "\n";
    return os;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
	cin >> n >> k;
	vector<int> prime(n + 1, 1);
	prime[0] = 0;
	prime[1] = 0;
	fore(i, 2, sqrt(n) + 10) if (prime[i]) fore(j, i, n / i) prime[i * j] = 0;
	vector<int> primes;
	forn(i, n + 1) if (prime[i]) primes.push_back(i);
	vector<int> noldbach(2 * n + 10, 0);
	forn(i, primes.size() - 1) noldbach[primes[i] + primes[i + 1] + 1] = 1;
	vector<int> noldbach_primes;
	forn(i, n + 1) if (prime[i] && noldbach[i]) noldbach_primes.push_back(i);
//	cout << noldbach_primes << "\n";
	if (count_if(begin(noldbach_primes), end(noldbach_primes), [n](int x) { return x <= n; }) >= k) {
		cout << "YES";
	} else {
		cout << "NO";
	}
    return 0;
}
