#include <bits/stdc++.h>

using namespace std;

void solve(int n, int k, vector<int>& a) {
	int l = 0, r = n - 1;

	while (l <= r) {
		if (a[l] <= k)
			++l;
		else if (a[r] <= k)
			--r;
		else
			break;
	}

	cout << (n - 1 - (r - l)) << "\n";
}

int main() {
	int n, k; cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	solve(n, k, a);

	return 0;
}