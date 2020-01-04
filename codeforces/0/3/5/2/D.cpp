#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> p(n);
	for (auto& pi: p) cin >> pi;

	int inv = 0;
	for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) inv += p[i] < p[j];

	if (inv & 1) {
		cout << (inv << 1) - 1;
	} else {
		cout << (inv << 1);
	}

	return 0;
}