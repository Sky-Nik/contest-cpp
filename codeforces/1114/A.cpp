#include <bits/stdc++.h>

using namespace std;

inline void solve(int x, int y, int z, int a, int b, int c) {
	cout << ((a < x || a + b < x + y || a + b + c < x + y + z) ? "NO" : "YES");
}

int main() {
	int x, y, z; cin >> x >> y >> z;
	int a, b, c; cin >> a >> b >> c;

	solve(x, y, z, a, b, c);

	return 0;
}