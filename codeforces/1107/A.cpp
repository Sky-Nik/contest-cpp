#include <bits/stdc++.h>

using namespace std;

void solve(int n, string& s) {
	if ((n > 2) || (n == 2 && s[0] < s[1])) {
		cout << "YES" << "\n" 
			<< 2 << "\n"
			<< s[0] << " " << s.substr(1, n - 1) << "\n";
	}
	else
		cout << "NO" << "\n";
}

int main() {
	int q; cin >> q;

	for (int i = 0; i < q; ++i) {
		int n; cin >> n;
		string s; cin >> s;

		solve(n, s);
	}

	return 0;
}