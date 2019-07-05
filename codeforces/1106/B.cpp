#include <bits/stdc++.h>

using namespace std;

typedef long long llong;

void solve(int n, int m, vector<llong>& a, vector<llong>& c, vector<pair<int, llong>>& td) {
	vector<pair<llong, int>> cheapest(n);
	for (int i = 0; i < n; ++i)
		cheapest[i] = make_pair(c[i], i);
	sort(cheapest.begin(), cheapest.end());
	int cheapest_idx = 0;

	for (auto tdi: td) {
		llong answer = 0;
		int t = tdi.first - 1;
		llong d = tdi.second;

		llong min_ = min(a[t], d);
		answer += min_ * c[t];
		a[t] -= min_;
		d -= min_;

		while (d > 0) {
			while (cheapest_idx < n && a[cheapest[cheapest_idx].second] == 0)
				++cheapest_idx;

			if (cheapest_idx == n)
				break;

			int t_ = cheapest[cheapest_idx].second;
			min_ = min(a[t_], d);
			answer += min_ * c[t_];
			a[t_] -= min_;
			d -= min_;
		}
		
		if (d == 0)
			cout << answer << "\n";
		else
			cout << 0 << "\n";
	}
}

int main() {
	int n, m; cin >> n >> m;

	vector<llong> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	vector<llong> c(n);
	for (int i = 0; i < n; ++i)
		cin >> c[i];

	vector<pair<int, llong>> td(m);
	for (int i = 0; i < m; ++i)
		cin >> td[i].first >> td[i].second;

	solve(n, m, a, c, td);
	
	return 0;
}