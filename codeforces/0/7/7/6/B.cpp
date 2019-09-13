#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> p(n + 2, 1);
    for (ll i = 2; i < n; ++i) {
    	if (p[i]) {
			for (ll j = i; i * j <= n + 1; ++j) {
				p[i * j] = 0;
			}
    	}
    }
    if (n == 1 || n == 2) {
    	cout << "1\n";
        for (ll i = 2; i < n + 2; ++i) {
        	cout << p[i] << " ";
        }
    } else {
    	cout << "2\n";
        for (ll i = 2; i < n + 2; ++i) {
        	cout << p[i] + 1 << " ";
        }
    }
    return 0;
}
