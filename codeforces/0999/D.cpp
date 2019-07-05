#include <bits/stdc++.h>

using namespace std;

typedef long long llong;

void solve(llong n, llong m, vector<llong>& a) {
	vector<vector<llong>> u(m);
	for (llong i = 0; i < n; ++i)
		u[a[i] % m].push_back(i);

	llong ans = 0;

	vector<pair<llong, llong>> free;

	for (llong pass = 0; pass < 2; ++pass) {
		for (llong i = 0; i < m; ++i) {
			for (int j = u[i].size() - 1; j >= n / m; --j) {
				free.push_back(make_pair(u[i].back(), i));
				u[i].pop_back();
			}

			for (int j = u[i].size(); j < n / m; ++j) {
				if (!free.empty()) {
					pair<llong, llong> f = free.back();
					
					llong to_add = (i - f.second + m) % m;
					
					ans += to_add;
					
					a[f.first] += to_add;

					u[i].push_back(f.first);

					free.pop_back();
				}
			}
		}
	}
	
	cout << ans << "\n";

	for (llong ai: a)
		cout << ai << " ";

	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	llong n, m; cin >> n >> m;

	vector<llong> a(n);
	for (llong i = 0; i < n; ++i)
		cin >> a[i];

	solve(n, m, a);

	return 0;
}