#include <bits/stdc++.h>

using namespace std;

typedef long long llong;

const llong MOD = 1e9 + 7;

inline vector<llong> count_remainders(int l, int r) {
	--l;
	return {r / 3 - l / 3, (r + 2) / 3 - (l + 2) / 3, (r + 1) / 3 - (l + 1) / 3};
}

void solve(int n, int l, int r) {
	vector<vector<llong>> dp(3, vector<llong>(n + 1, 0));
	dp[0][0] = 1;

	vector<llong> abc = count_remainders(l, r);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				dp[(j + k) % 3][i + 1] += dp[j][i] * abc[k];
				dp[(j + k) % 3][i + 1] %= MOD;
			}
		}
	}
	
	cout << dp[0][n] << "\n";
}

int main() {
	int n, l, r; cin >> n >> l >> r;

	solve(n, l, r);

	return 0;
}