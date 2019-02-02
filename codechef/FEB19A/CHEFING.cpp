#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> f(26, 0);
	string s; int pos;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		for (char c: s) {
			pos = static_cast<int>(c) - static_cast<int>('a');
			if (f[pos] == i)
				++f[pos];
		}
	}

	cout << count(begin(f), end(f), n) << "\n";
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		solve();
	}

	return 0;
}