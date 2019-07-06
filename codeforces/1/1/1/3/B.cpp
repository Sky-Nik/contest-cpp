#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
	sort(begin(a), end(a));
	int max_decr = 0;
	for (int i = 1; i < n; ++i)
		for (int x = 1; x <= a[i]; ++x)
			if (a[i] % x == 0)
				max_decr = max(max_decr, a[0] + a[i] - a[0] * x - a[i] / x);
	cout << accumulate(begin(a), end(a), 0) - max_decr;
	return 0;
}