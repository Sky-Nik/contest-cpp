#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, v; cin >> n >> v;

	int pos = 1, cost = 0, fuel = 0;

	while (pos < n) {
		while (((n - pos) > fuel) && (v > fuel)) {
			++fuel;
			cost += pos;
		}
		++pos;
		--fuel;
	}

	cout << cost;
	
	return 0;
}