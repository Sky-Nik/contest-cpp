#include <bits/stdc++.h>

using namespace std;

void solve(int n, int m, int k, vector<int>& b) {
	if (n == 1) {
		cout << 1 << "\n";
		return;
	}

	vector<int> d(n - 1);
	for (int i = 0; i < n - 1; ++i)
		d[i] = b[i + 1] - b[i];

	sort(begin(d), end(d));

	int ans = k;

	for (int i = 0; i < n - k; ++i)
		ans += d[i];
	
	cout << ans << "\n";
}

int main() {
	int n, m, k; cin >> n >> m >> k; 

	vector<int> b(n);
	for (int i = 0; i < n; ++i)
		cin >> b[i];

	solve(n, m, k, b);

	return 0;
}