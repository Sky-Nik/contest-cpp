#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	
	vector<int> f(26, 0);
	for (char c: s) ++f[static_cast<int>(c) - static_cast<int>('A')];

	sort(begin(f), end(f));

	int a = 1e9, c, l;
	for (int i = 1; i <= 26; ++i) {
        if (s.length() % i != 0)
               continue;
        l = s.length() / i;
		c = 0;
		for (int j = 0; j < 26 - i; ++j) c += f[j];
		for (int j = 26 - i; j < 26; ++j) c += abs(f[j] - l);
		c >>= 1;
		a = min(a, c);
	}

	cout << a << "\n";
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)	solve();

	return 0;
}