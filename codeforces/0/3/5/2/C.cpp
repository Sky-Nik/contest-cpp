#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	double aid;
	vector<int> a(n << 1);
	for (auto& ai: a) {
		cin >> aid;
		ai = (int)(aid * 1'000 + .1) % 1'000;
	}

	int d = accumulate(a.begin(), a.end(), 0LL);
	int z = count(a.begin(), a.end(), 0);
	int nz = (n << 1) - z;

	int u_opt_lower = d / 1'000,
		u_opt_upper = (d + 999) / 1'000,
		u_upper_bound = min(nz, n),
		u_lower_bound = max(0, n - z);

	int pre_answer = 1'000'000'000;
	pre_answer = min(pre_answer, abs(d - 1'000 * u_lower_bound));
	pre_answer = min(pre_answer, abs(d - 1'000 * u_upper_bound));
	if (u_lower_bound <= u_opt_lower && u_opt_lower <= u_upper_bound) {
		pre_answer = min(pre_answer, abs(d - 1'000 * u_opt_lower));
	}
	if (u_lower_bound <= u_opt_upper && u_opt_upper <= u_upper_bound) {
		pre_answer = min(pre_answer, abs(d - 1'000 * u_opt_upper));
	}

	cout << fixed << setprecision(3) << (pre_answer + .1) / 1'000.;

	return 0;
}