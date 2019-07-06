#include <bits/stdc++.h>

using namespace std;

typedef long long llong;

void solve(int n, vector<llong>& a) {
	sort(a.begin(), a.end());

	llong ans = 0;
	for (int i = 0; (i << 1) < n; ++i)
		ans += (a[i] + a[n - 1 - i]) * (a[i] + a[n - 1 - i]);

	cout << ans << "\n";
}

int main() {
	int n; cin >> n;

	vector<llong> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	solve(n, a);

	return 0;
}