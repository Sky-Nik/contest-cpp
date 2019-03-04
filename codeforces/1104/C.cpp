#include <bits/stdc++.h>

using namespace std;

void solve(string& s) {
	bool h = false, v = false;

	for (char c: s) {
		if (c == '0') {
			if (v)
				cout << 1 << " " << 1 << "\n";
			else // !v
				cout << 3 << " " << 1 << "\n";
			v = !v;
		} else { // c == '1'
			if (h)
				cout << 1 << " " << 1 << "\n";
			else // !h
				cout << 1 << " " << 3 << "\n";
			h = !h;
		}
	}
}

int main() {
	string s; cin >> s;

	solve(s);

	return 0;
}