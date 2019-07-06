#include <bits/stdc++.h>

using namespace std;

pair<char, bool> check_pos(int n, int k, int& pos_i, string& s) {
	if (pos_i + k > n) {
		pos_i = n;
		return make_pair('\0', false);
	}

	char c = s[pos_i];
	for (int pos = pos_i; pos < pos_i + k; ++pos) {
		if (s[pos] != c) {
			pos_i = pos;
			return make_pair('\0', false);
		}
	}

	pos_i += k;
	return make_pair(s[pos_i - k], true);
}

void solve(int n, int k, string& s) {
	map<char, int> pre_x;

	int pos_i = 0;
	while (pos_i < n) {
	pair<char, bool> cb = check_pos(n, k, pos_i, s);
		if (cb.second) {
			if (pre_x.find(cb.first) == pre_x.end()) {
				pre_x[cb.first] = 0;
			}
			++pre_x[cb.first];
		}
	}

	int x = 0;
	for (auto [k, v]: pre_x) {
		x = max(x, v);
	}

	cout << x << "\n";
}

int main() {
	int n, k; cin >> n >> k;

	string s; cin >> s;

	solve(n, k, s);

	return 0;
}