#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, c0 = 0, c5 = 0, t;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (!t) {
			++c0;
		} else {
			++c5;
		}
	}

	if (!c0) {
		cout << -1;
	} else {
		for (int i = 0; i < (c5 / 9) * 9; ++i) {
			cout << 5;
		}
		if (c5 >= 9) {
			for (int i = 0; i < c0; ++i) {
				cout << 0;
			}
		} else {
			cout << 0;
		}
	}

	return 0;
}