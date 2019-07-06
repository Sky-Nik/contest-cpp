#include <bits/stdc++.h>

using namespace std;

void solve(int b, int k, vector<int>& a) {
	if (b & 1) {
		bool even = true;

		for (int i = 0; i < k; ++i)
			if (a[i] & 1)
				even = !even;

		cout << (even ? "even" : "odd") << "\n";
	} else {
		cout << ((a[k - 1] & 1) ? "odd" : "even") << "\n";
	}
}

int main() {
	int b, k; cin >> b >> k;

	vector<int> a(k);
	for (int i = 0; i < k; ++i)
		cin >> a[i];

	solve(b, k, a);

	return 0;
}