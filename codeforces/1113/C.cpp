#include <bits/stdc++.h>

using namespace std;

typedef long long llong;

int main() {
	int n; cin >> n;
	vector<llong> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
	map<pair<llong, bool>, llong> cnt;
	llong cur_xor = 0;
	cnt[{0, 1}] = 1;
	for (int i = 0; i < n; ++i) {
		cur_xor ^= a[i];
		if (cnt.find({cur_xor, i & 1}) == end(cnt)) cnt[{cur_xor, i & 1}] = 0;
		++cnt[{cur_xor, i & 1}];
	}
	llong ans = 0;
	for (auto [k, v]: cnt) ans += (v * (v - 1)) >> 1;
	cout << ans;
	return 0;
}