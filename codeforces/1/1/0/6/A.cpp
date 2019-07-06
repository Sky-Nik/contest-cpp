#include <bits/stdc++.h>

using namespace std;

void solve(int n, vector<string>& m) {
	int ans = 0;

	for (int i = 1; i + 1 < n; ++i)
		for (int j = 1; j + 1 < n; ++j)
			if (m[i][j] == 'X' && m[i - 1][j - 1] == 'X' && m[i - 1][j + 1] == 'X' && m[i + 1][j - 1] == 'X' && m[i + 1][j + 1] == 'X')
				++ans;

	cout << ans << "\n";
}

int main() {
	int n; cin >> n;

	vector<string> m(n);
	for (int i = 0; i < n; ++i)
		cin >> m[i];

	solve(n, m);
	
	return 0;
}