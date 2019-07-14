#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAXN = 300000 + 1000;
// const ll MAXN = 1000;
ll L[MAXN << 2], R[MAXN << 2], 
    M[MAXN << 2], C[MAXN << 2], 
    LEFT[MAXN << 2], RIGHT[MAXN << 2];

void build_tree(ll v, ll LEFT_, ll RIGHT_) {
    LEFT[v] = LEFT_;
    RIGHT[v] = RIGHT_;
    L[v] = (v << 1);
    R[v] = ((v << 1) + 1);
    C[v] = 0;
    M[v] = 0;
    if (LEFT_ != RIGHT_) {
        ll middle = (LEFT_ + RIGHT_) >> 1;
        build_tree(L[v], LEFT_, middle);
        build_tree(R[v], middle + 1, RIGHT_);
    }
}

void UPDATE(ll v, ll a, ll b, ll delta) {
    // v ~ [LEFT[v]..RIGHT[v]]
    // [a..b] += delta, [a..b] in [LEFT[v]..RIGHT[v]]
    // cout << "\nLEFT[" << v << "] = " << LEFT[v] << "\n";
    // cout << "\nRIGHT[" << v << "] = " << RIGHT[v] << "\n";
    if (LEFT[v] == a && RIGHT[v] == b) {
        C[v] += delta;
        M[v] += delta;
        return;
    }
    ll m = (LEFT[v] + RIGHT[v]) >> 1;
    if (m >= a) {
        UPDATE(L[v], a, min(b, m), delta);
    }
    if (m + 1 <= b) {
        UPDATE(R[v], max(m + 1, a), b, delta);   
    }
    M[v] = max(M[L[v]], M[R[v]]) + C[v];
    return;
}

ll upper(ll value, vector<ll>& y) {
    y.push_back(value + 1);
    ll lower_bound = 0, upper_bound = y.size();
    while (lower_bound < upper_bound) {
        ll middle = (lower_bound + upper_bound) >> 1;
        if (y[middle] > value) {
            upper_bound = middle;
        } else {
            lower_bound = middle + 1;
        }
    }
    y.pop_back();
    return lower_bound - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, r;
    cin >> n >> r;
    vector<pair<int, int>> p(n);
    vector<ll> x(n), y(n);
    for (ll i = 0, xi, yi; i < n; ++i) {
        cin >> xi >> yi;
        // *= (1 + i), 
        // rotates point 
        // by 45 degrees 
        // counter-clock-wise
        x[i] = xi - yi;
        y[i] = xi + yi;
        p[i].first = x[i];
        p[i].second = y[i];
    }
    // width of a strip 
    // after rotation
    // is twice bigger than r
    ll w = r << 1;
    sort(begin(p), end(p));
    set<ll> s(begin(y), end(y));
    y.assign(begin(s), end(s));
    sort(begin(y), end(y));
    ll j = 0;
    ll answer = 0;
    build_tree(1, 0, n - 1);
    for (ll i = 0; i < n; ++i) {
        while (j < n && p[j].first <= p[i].first + w) {
            UPDATE(1, upper(p[j].second, y), upper(p[j].second + w, y), +1);
            ++j;
        }
        answer = max(answer, M[1]);
        UPDATE(1, upper(p[i].second, y), upper(p[i].second + w, y), -1);
    }
    cout << answer;
    return 0;
}