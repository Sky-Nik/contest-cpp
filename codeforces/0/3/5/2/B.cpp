#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, ai;
	cin >> n;
	unordered_map<int, vector<int>> mxp;
	for (int i = 0; i < n; ++i) {
		cin >> ai;
		mxp[ai].push_back(i);
	}

	int px;
	bool flag;
	vector<pair<int, int>> vxp;
	for (auto& [x, p]: mxp) {
		if (p.size() == 1) {
			vxp.push_back(make_pair(x, 0));
		} else {
			px = p[1] - p[0];
			flag = true;

			for (int i = 0; i + 1 < p.size(); ++i) {
				flag &= p[i + 1] - p[i] == px;
			}

			if (flag) {
				vxp.push_back(make_pair(x, px));
			}
		}
	}

	sort(vxp.begin(), vxp.end());
	cout << vxp.size() << "\n";
	for (auto& xp: vxp) {
		cout << xp.first << " " << xp.second << "\n";
	}

	return 0;
}