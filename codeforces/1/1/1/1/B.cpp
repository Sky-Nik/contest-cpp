#include <bits/stdc++.h>

using namespace std;

typedef long long llong;
typedef long double ldouble;

void solve(llong n, llong k, llong m, vector<llong>& a) {
	sort(begin(a), end(a));

	llong s = accumulate(begin(a), end(a), 0ll);

	ldouble ans = 0;

	for (llong l = 0; l < min(n, m + 1); ++l) {
		ans = max(ans, 1.l * (s + min(m - l, k * (n - l))) / (n - l));

		s -= a[l];
	}

	cout << setprecision(20) << ans << "\n";
}

int main() {
	llong n, k, m; cin >> n >> k >> m;

	vector<llong> a(n);
	for (llong i = 0; i < n; ++i)
		cin >> a[i];

	solve(n, k, m, a);

	return 0;
}