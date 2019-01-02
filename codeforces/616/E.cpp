#include <algorithm>
#include <iostream>

typedef long long llong;

const llong mod = static_cast<llong>(1e9) + 7;

inline llong norm(llong& a) {
	a %= mod;
	
	if (a < 0)
		a += mod;
}

inline llong mul(llong a, llong b) {
	norm(a), norm(b);
	return (a * b) % mod;
}

inline llong add(llong a, llong b) {
	norm(a), norm(b);
	return (a + b) % mod;
}

inline llong sub(llong a, llong b) {
	norm(a), norm(b);
	
	a -= b;
	norm(a);

	if (a < 0)
		a += mod;

	return a;
}

inline llong sum(llong n) {
	return mul(
		mul(n, n + 1), 
		(mod + 1) / 2 // 1 / 2 modulo mod
	);
}

inline llong sum(llong lf, llong rg) {
	return sub(sum(rg), sum(lf - 1));
}

inline llong calcDiv(llong n, llong m) {
	m = std::min(n, m);

	llong ans = 0, minVal = m;
	for (llong i = 1; i * i <= n; ++i) {
		llong lf = n / (i + 1), rg = n / i;

		rg = std::min(rg, m);

		if (lf >= rg)
			continue;

		minVal = lf; // (lf, rg]

		ans = add(ans, mul(i, sum(lf + 1, rg)));
	}

	for (llong i = 1; i <= minVal; ++i)
		ans = add(ans, mul(n / i, i));

	return ans;
}

inline calcMod(llong n, llong m) {
	llong ans = mul(n, m);
	ans = sub(ans, calcDiv(n, m));
	return ans;
}

void solve(llong n, llong m) {
	std::cout << calcMod(n, m);
}

int main() {
	llong n, m;
	std::cin >> n >> m;	

	solve(n, m);

	return 0;
}