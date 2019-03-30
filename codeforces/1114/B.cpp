#include <bits/stdc++.h>

using namespace std;

typedef long long llong;

void solve(int n, int m, int k, vector<int>& a) {
	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; ++i) 
		p[i] = make_pair(a[i], i);

	sort(p.rbegin(), p.rend());
	
	llong s = 0;
	vector<bool> u(n, false);
	for (int i = 0; i < k * m; ++i) {
		s += p[i].first;
		u[p[i].second] = true;
	}
	cout << s << "\n";

	int c = 0, cc = 1;
	for (int i = 0; i < n; ++i) {
		if (u[i])
			++c;

		if (c == m && cc < k) {
			++cc;
			cout << i + 1 << " ";
			c = 0;
		}
	}
}

int main() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(n); 
	for (int i = 0; i < n; ++i) 
		cin >> a[i];

	solve(n, m, k, a);

	return 0;
}