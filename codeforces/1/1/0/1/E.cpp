#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int X = 0, Y = 0;

	char t; int x, y;
	for (int i = 0; i < n; ++i) {
		cin >> t >> x >> y;

		if (t == '+') {
			X = max(min(x, y), X);
			Y = max(max(x, y), Y);
		}

		if (t == '?') {
			if (X <= min(x, y) && Y <= max(x, y))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}
