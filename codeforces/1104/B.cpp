#include <bits/stdc++.h>

using namespace std;

void solve(string& s) {
	stack<char> st;

	int count = 0;
	for (char c: s) {
		if (!st.empty() && c == st.top()) {
			st.pop();
			++count;
		} else {
			st.push(c);
		}
	}

	cout << ((count & 1) ? "Yes" : "No") << "\n";
}

int main() {
	string s; cin >> s;

	solve(s);

	return 0;
}