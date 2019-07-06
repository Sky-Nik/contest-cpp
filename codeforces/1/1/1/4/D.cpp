#include <bits/stdc++.h>

using namespace std;

void solve(int n, vector<int>& c) {
	vector<int> r(c);

	vector<vector<int>> dp(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (c[i] == r[j]) 
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else 
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << n - (dp[n][n] + 1) / 2;
}

int main() {
	int n; cin >> n;

	vector<int> c(n)
	for (int i = 0; i < n; ++i)
		cin >> c[i];
	
	solve(n, c);
	
	return 0;
}