#include <bits/stdc++.h>

using namespace std;

typedef long long llong;

void solve(int n, int k, vector<llong>& a, string& s) {
	llong dmg = 0; int i = 0, j = 1;

	while (j < n) {
		if (s[i] != s[j]) {
			sort(begin(a) + i, begin(a) + j);
			dmg += accumulate(begin(a) + max(i, j - k), begin(a) + j, 0ll);
			i = j; 
		}

		++j;
	}

	sort(begin(a) + i, begin(a) + j);
	dmg += accumulate(begin(a) + max(i, j - k), begin(a) + j, 0ll);

	cout << dmg << "\n";
}

int main() {
	int n, k; cin >> n >> k;

	vector<llong> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	string s; cin >> s;

	solve(n, k, a, s);

	return 0;
}