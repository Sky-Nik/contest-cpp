#include <bits/stdc++.h>

using namespace std;

inline bool vowel(char c) {
	return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
}

void solve(string& s, string& t) {
	if (s.length() != t.length()) {
		cout << "No" << "\n"; return;
	}
	
	bool ok = true;

	for (int i = 0; i < s.length(); ++i)
		if (vowel(s[i]) != vowel(t[i]))
			ok = false;
	
	cout << (ok ? "Yes" : "No") << "\n";
}

int main() {
	string s, t; cin >> s >> t;

	solve(s, t);

	return 0;
}