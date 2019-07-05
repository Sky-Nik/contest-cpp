#include <bits/stdc++.h>

using namespace std;

void solve(int n, string& t) {
	for (int d = 1; d <= n; ++d)
		if (n % d == 0)
			reverse(begin(t), begin(t) + d);

	cout << t << "\n";
}

int main() {
	int n; cin >> n;

	string t; cin >> t;

	solve(n, t);

	return 0;
}