#include <bits/stdc++.h>
using namespace std;
#define elif else if
typedef long long ll;
const ll mod = 1000003;

ll bin_pow(ll n, ll p) {
    if (p == 0) {
        return 1;
    }
    return (bin_pow((n * n) % mod, p >> 1) * ((p & 1) ? n : 1)) % mod;
}

ll mod_inv(ll n) {
    return bin_pow(n, mod - 2);
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    vector<ll> a(11);
    vector<vector<ll>> c(11, vector<ll>(12, 1));
    for (int i = 0; i < 11; ++i) {
        for (int j = 1; j < 11; ++j) {
            c[i][j] = (i * c[i][j - 1]) % mod;
        }
        cout << "? " << i << "\n";
        cout.flush();
        cin >> c[i][11];
    }
    for (int i = 0; i < 11; ++i) {
        ll cii_inv = mod_inv(c[i][i]);
        for (int j = i; j < 12; ++j) {
            c[i][j] *= cii_inv;
            c[i][j] %= mod;
        }
        for (int k = i + 1; k < 11; ++k) {
            ll cki = c[k][i];
            for (int j = i; j < 12; ++j) {
                c[k][j] -= cki * c[i][j];
                c[k][j] %= mod;
                c[k][j] += mod;
                c[k][j] %= mod;
            }
        }
    }
    for (int i = 10; i >= 0; --i) {
        for (int k = i - 1; k >= 0; --k) {
            ll cki = c[k][i];
            c[k][i] -= cki * c[i][i];
            c[k][i] %= mod;
            c[k][i] += mod;
            c[k][i] %= mod;

            c[k][11] -= cki * c[i][11];
            c[k][11] %= mod;
            c[k][11] += mod;
            c[k][11] %= mod;
        }
    }

    for (int i = 0; i < 11; ++i) {
        a[i] = c[i][11];
    }

    ll x0 = -1;
    for (ll x = 0; x < mod; ++x) {
        ll ans = 0, p = 1;
        for (int i = 0; i < 11; ++i) {
            ans += a[i] * p;
            ans %= mod;
            p *= x;
            p %= mod;
        }
        if (ans == 0) {
            x0 = x;
        }
    }
    cout << "! " << x0 << "\n";
    cout.flush();
    return 0;
}