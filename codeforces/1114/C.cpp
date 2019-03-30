#include <bits/stdc++.h>

using namespace std;

typedef long long llong;

vector<pair<llong, llong>> factorize(llong b) {
	vector<pair<llong, llong>> a;

	for (llong d = 2; d * d <= b; ++d) {
		if (b % d == 0) {
			a.push_back(make_pair(d, 0));

			while (b % d == 0) {
				b /= d;
				++a[size(a) - 1].second;
			}
		}
	}

	if (b > 1)
		a.push_back(make_pair(b, 1));

	return a;
}

void solve(llong n, llong b) {
	vector<pair<llong, llong>> f = factorize(b);

	vector<llong> deg;

	for (llong i = 0; i < size(f); ++i) {
		llong a = 0;
		llong power_prime = f[i].first;
		
		while (true) {
			a += n / power_prime;
			if (n / power_prime < f[i].first)
				break;
			power_prime *= f[i].first;
		}

		deg.push_back(a);
	}

	llong a = n;

	for (llong i = 0; i < size(deg); ++i)
		a = min(a, deg[i] / f[i].second);

	cout << a;
}

int main() {
	llong n, b; cin >> n >> b;

	solve(n, b);

	return 0;
}