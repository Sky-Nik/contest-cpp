#include <bits/stdc++.h>

using namespace std;

void solve(int n, int k, string& s) {
	char c = 'a';

	int i = 0;

	vector<int> u(n, false);

	while (k > 0) {
		while (i < n && s[i] != c)
			++i;

		if (i == n) {
			i = 0;
			c++;
		} else {
			--k;
			u[i] = true;
			++i;
		}
	}

	for (int i = 0; i < n; ++i)
		if (!u[i])
			cout << s[i];

	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); 

	cin.tie(NULL);

	int n, k; cin >> n >> k;

	string s; cin >> s;

	solve(n, k, s);

	return 0;
}