#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

const int inf = 1e9;

int N = 16;

vvi diff(N, vi(N));

vvi diff2(N, vi(N));

vvvi dp(1 << N, vvi(N, vi(N)));

int n, m;

int get_dp(int i, int j, int first) {
	if (dp[i][j][first] != -1) 
		return dp[i][j][first];

	int ii = i;

	int prev_i = i - (1 << j);

	for (int k = 0; k < n; ++k)	{
		if (ii % 2 == 1) {
			if (k != j && (k != first || prev_i == (1 << k))) {
				int cur = min(get_dp(prev_i, k, first), diff[k][j]);

				dp[i][j][first] = max(dp[i][j][first], cur);
			}
		}
		ii >>= 1;
	}

	return dp[i][j][first];
}

int main() {
	cin >> n >> m;

	vvi a(n, vi(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];

	if (n == 1) {
		int ans = inf;

		for (int l = 0; l < m - 1; ++l) 
			ans = min(ans, abs(a[0][l] - a[0][l + 1]));

		cout << ans;

		return 0;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j)
				continue;

			diff[i][j] = inf;

			for (int l = 0; l < m; ++l) 
				diff[i][j] = min(diff[i][j], abs(a[i][l] - a[j][l]));
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j)
				continue;

			diff2[i][j] = inf;

			for (int l = 0; l < m - 1; ++l) 
				diff2[i][j] = min(diff2[i][j], abs(a[i][l] - a[j][l + 1]));
		}
	}

	for (int i = 0; i < (1 << n); ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				dp[i][j][k] = -1;

	for (int i = 0; i < n; ++i)
		dp[1 << i][i][i] = inf;

	int ans = 0;

	for (int first = 0; first < n; ++first) {
		for (int last = 0; last < n; ++last) {
			if (last != first) {
				int dp_first_last = get_dp((1 << n) - 1, last, first);

				int diff_2_last_first = diff2[last][first];

				int cur = min(dp_first_last, diff_2_last_first);

				ans = max(ans, cur);
			}
		}
	}

	cout << ans;
}