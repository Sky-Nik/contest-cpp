#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int d[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int c(int n) {
	int a = 0;
	while (n > 0) {
		a += d[n % 10];
		n /= 10;
	}
	return a;
}
int main() {
	int a, b;
	cin >> a >> b;
	ll s = 0;
	for (int n = a; n <= b; ++n) s += c(n);
	cout << s;
	return 0;
}