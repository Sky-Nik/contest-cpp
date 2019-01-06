#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const ll mod = 1e9 + 7;

vpll factorize(ll n) {
	vpll ans;
	ll d = 2, s = ceil(sqrt(n));
	
	while (n > 1 && d <= s) {
		if (n % d == 0)
			ans.push_back(pll(d, 0));

		while (n % d == 0) {
			++ans.back().second;
			n /= d;
		}
        
        ++d;
	}

	if (n > 1)
		ans.push_back(pll(n, 1));

	return ans;
}

ll bin_pow(ll n, ll p) {
	ll ans = 1;
	
	while (p) {
		if (p & 1) {
			ans *= n;
			ans %= mod;
        }
            
		n *= n;
		n %= mod;
		p >>= 1;
	}

	return ans;
}

ll mod_inv(ll n) {
	return bin_pow(n, mod - 2);
}

int main() {
	ll n, k;
	cin >> n >> k;

	vpll divs = factorize(n);

	ll ans = 1;

	vll inv(60, 0);
	for (ll i = 1; i < 60; ++i)
		inv[i] = mod_inv(i);

	for (auto [div, deg]: divs) {
		vvll dp(k + 1, vll(deg + 1, 0));
		dp[0][deg] = 1;

		for (ll i = 0; i < k; ++i) {
			for (ll j = 0; j <= deg; ++j) {
				ll to_add = (inv[j + 1] * dp[i][j]) % mod;
				for (ll m = 0; m <= j; ++m) {
					dp[i + 1][m] += to_add;
					dp[i + 1][m] %= mod;
				}
			}
		}

		ll part_ans = 0, pow = 1;
		for (ll j = 0; j <= deg; ++j) {
			part_ans += pow * dp[k][j];
			part_ans %= mod;
			pow *= div;
			pow %= mod;
		}

		ans *= part_ans;
		ans %= mod;
	}

	cout << ans;

	return 0;
}