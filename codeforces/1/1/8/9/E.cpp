#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod4pow(ll a, ll p) {
    a = (a * a) % p;
    return (a * a) % p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, p, k;
    cin >> n >> p >> k;
    vector<ll> a(n);
    map<ll, ll> a4k;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        /* (a_i + a_j) (a_i^2 + a_j^2) = k (mod p)
         * (a_i - a_j) (a_i + a_j) (a_i^2 + a_j^2) = (a_i - a_j) k (mod p)
         * (a_i^2 - a_j^2) (a_i^2 + a_j^2) = (a_i - a_j) k (mod p)
         * a_i^4 - a_j^4 = (a_i - a_j) k (mod p)
         * a_i^4 - k a_i = a_j^4 - k a_j (mod p) */
        ll ai4k = (mod4pow(a[i], p) - k * a[i]) % p;
        ai4k = (ai4k + p) % p;
        if (a4k.count(ai4k) == 0) {
            a4k.insert(make_pair(ai4k, 1));
        } else {
            ++a4k[ai4k];
        }
    }
    ll answer = 0;
    for (auto const& [key, val]: a4k) {
        answer += ((val - 1ll) * val) >> 1;
        //cout << "map[" << key << "] = " << val << "\n";
    }
    cout << answer;
    return 0;
}