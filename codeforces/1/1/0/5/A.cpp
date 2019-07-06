#include <bits/stdc++.h>

using namespace std;

const int MAX_A = 100;

inline int dist(int ai, int t) {
	return max(abs(ai - t) - 1, 0);
}

int cost(int n, vector<int>& a, int t) {
	int cur_cost = 0;

	for (int ai: a)
		cur_cost += dist(ai, t);
	
	return cur_cost;
}

void solve(int n, vector<int>& a) {
	int opt_cost = MAX_A * n, opt_t = -1;

	for (int t = 1, cur_cost; t < MAX_A; ++t) {
		cur_cost = cost(n, a, t);
		if (cur_cost < opt_cost) {
			opt_cost = cur_cost;
			opt_t = t;
		}
	}

	cout << opt_t << " " << opt_cost << "\n";
}

int main() {
	int n; cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) 
		cin >> a[i];
	
	solve(n, a);

	return 0;
}