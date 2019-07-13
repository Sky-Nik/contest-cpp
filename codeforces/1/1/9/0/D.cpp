#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define elif else if
#define forn(i, n) for(ll i = 0; i < n; ++i)
#define fore(i, l, r) for(ll i = l; i < r; ++i)
//#define sum(a) accumulate(begin(a), end(a), 0ll)

const ll MAXN = 200100;

ll t[4*MAXN];

void build (ll v, ll tl, ll tr) {
    if (tl != tr) {
        ll tm = (tl + tr) / 2;
        build (v*2, tl, tm);
        build (v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

ll sum (ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v];
    ll tm = (tl + tr) / 2;
    return sum (v*2, tl, tm, l, min(r,tm))
        + sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}

void update (ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr)
        t[v] = new_val;
    else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update (v*2, tl, tm, pos, new_val);
        else
            update (v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> p(n);
    set<ll> x;
    forn(i, n) {
        cin >> p[i].second >> p[i].first; // (yi, xi)
        x.insert(p[i].second);
    }
    map<ll, ll> x_to_i;
    ll i = 0;
    for (const auto& xi: x) {
        x_to_i[xi] = i++;
    }
    sort(begin(p), end(p), greater<>());
    build(1, 0, size(x) - 1);
    ll cy = p[0].first, ans = 0ll;
    set<ll> cx;
    for (const auto& [yi, xi]: p) {
        if (cy != yi) {
            vector<ll> vcx(begin(cx), end(cx));
            ll so = sum(1, 0, size(x) - 1, 0, n - 1);
            ans += so * (so + 1) >> 1;
            ll sl = sum(1, 0, size(x) - 1, 0, vcx[0] - 1);
            ans -= sl * (sl + 1) >> 1;
            fore(i, 1, size(vcx)) {
                ll si = sum(1, 0, size(x) - 1, vcx[i - 1] + 1, vcx[i] - 1);
                ans -= si * (si + 1) >> 1;
            }
            ll sr = sum(1, 0, size(x) - 1, vcx[size(vcx) - 1] + 1, size(x) - 1);
            ans -= sr * (sr + 1) >> 1;
            for (const auto& i: cx) {
                update(1, 0, size(x) - 1, i, 1);
            }
        } else {
            cx.insert(x_to_i[xi]);
        }
    }
    vector<ll> vcx(begin(cx), end(cx));
    ll so = sum(1, 0, size(x) - 1, 0, n - 1);
    ans += so * (so + 1) >> 1;
    ll sl = sum(1, 0, size(x) - 1, 0, vcx[0] - 1);
    ans -= sl * (sl + 1) >> 1;
    fore(i, 1, size(vcx)) {
        ll si = sum(1, 0, size(x) - 1, vcx[i - 1] + 1, vcx[i] - 1);
        ans -= si * (si + 1) >> 1;
    }
    ll sr = sum(1, 0, size(x) - 1, vcx[size(vcx) - 1] + 1, size(x) - 1);
    ans -= sr * (sr + 1) >> 1;
    cout << ans;
    return 0;
}