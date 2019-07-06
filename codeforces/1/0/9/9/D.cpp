#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

const ll inf = 1e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    
    vll p(n), h(n, 1);
    for (ll i = 1; i < n; ++i) {
        cin >> p[i]; --p[i]; 

        h[i] = h[p[i]] + 1;
    }
    
    vll s(n);
    for (ll i = 0; i < n; ++i) 
        cin >> s[i];
    
    vll a(n, inf); a[0] = s[0];
    for (ll i = 1; i < n; ++i)
        if (h[i] % 2 == 1) 
            a[p[i]] = min(a[p[i]], s[i] - s[p[p[i]]]);
    
    for (ll i = 1; i < n; ++i) {
        if (a[i] < 0) {
            cout << -1; 
            return 0;
        }

        if (a[i] == inf) 
            a[i] = 0;

        if (h[i] % 2 == 1) 
            a[i] = s[i] - a[p[i]] - s[p[p[i]]];
    }
    
    cout << accumulate(begin(a), end(a), 0ll);
}