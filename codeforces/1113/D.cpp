#include <bits/stdc++.h>

using namespace std;

bool possible(string s) {
	int n = s.length();
	if (n & 1) {
		for (int i = 1; i < n; ++i)
			if ((s[i] != s[0]) && (i != (n >> 1)))
				return true;
		return false;
	} else {
		for (int i = 1; i < n; ++i)
			if (s[i] != s[0])
				return true;
		return false;
	}
}

bool inline is_pal(string s) {
	string t = s;
	reverse(begin(t), end(t));
	return t == s;
}

int main() {
	string s; cin >> s;
	int n = s.length();
	
	if (possible(s)) {
		for (int i = 0; i < n; ++i) {
			string t = s.substr(i, n - i) + s.substr(0, i);
			if (is_pal(t) && (t != s)) {
				cout << 1;
				return 0;
			}
		}
		cout << 2;
	} else {
		cout << "Impossible";
	}
	return 0;
}