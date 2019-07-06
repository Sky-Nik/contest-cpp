#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;
string s_;

int f(int i, int j) {
	if (i > j)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	dp[i][j] = f(i, j - 1) + 1;
	for (int k = i; k < j; ++k)
		if (s_[k] == s_[j])
			dp[i][j] = min(dp[i][j], f(i, k) + f(k + 1, j - 1));

	return dp[i][j];
}

int main() {
	int n; cin >> n;

	string s; cin >> s;

	s_ += s[0];
	for (int i = 0, j = 0; i < n; ++i) {
		if (s[i] != s_[j]) {
			s_ += s[i];
			++j;
		}
	}

	n = s_.length();

	dp.resize(n);
  for (int i = 0; i < n; ++i) {
    dp[i].resize(n);
		for (int j = 0; j < n; ++j)
      dp[i][j] = -1;
    dp[i][i] = 1;
  }

	cout << f(0, n - 1) << "\n";

	return 0;
}