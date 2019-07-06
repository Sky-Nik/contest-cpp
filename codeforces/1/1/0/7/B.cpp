#include <bits/stdc++.h>

using namespace std;

typedef long long llong;

void solve(llong k, int x) {
	cout << 9 * (k - 1) + x << "\n";
}

int main() {
	int n; cin >> n;

	for (int i = 0; i < n; ++i) {
		llong k; int x; cin >> k >> x;
		solve(k, x);
	}

	return 0;
}