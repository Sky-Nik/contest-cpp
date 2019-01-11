#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef tuple<int, int, int> ti;
typedef vector<ti> vti;
typedef vector<vi> vvi;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
	int n;
	cin >> n;

	int ans = 0;

	vi a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] > 1)
			ans = 1;
	}

	vvi g(n);

	vti xy(n - 1); int xi, yi;
	for (int i = 0; i < n - 1; ++i) {
		cin >> xi >> yi;
		--xi; --yi;
		xy[i] = make_tuple(xi, yi, gcd(a[xi], a[yi]));
		g[xi].push_back(yi); g[yi].push_back(xi);
	}



	// TODO

	cout << ans;

	return 0;
}