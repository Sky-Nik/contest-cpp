#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dsu_get(ll v, vector<ll>& p) {
    if (v == p[v]) {
        return v;
    } else {
        p[v] = dsu_get(p[v], p);
        return p[v];
    }
}

void dsu_unite(ll a, ll b, vector<ll>& p) {
    a = dsu_get(a, p);
    b = dsu_get(b, p);
    if (rand() & 1)
        swap (a, b);
    if (a != b)
        p[a] = b;
}

ll kruskal(ll& n, ll& m, vector<pair<ll, pair<ll, ll>>> g) {
    ll cost = 0;
    vector<ll> p(n);
    for (ll i = 0; i < n; ++i) {
        p[i] = i;
    }
    sort(g.begin(), g.end());
    for (ll i = 0; i < m; ++i) {
        ll a = g[i].second.first, b = g[i].second.second, l = g[i].first;
        if (dsu_get(a, p) != dsu_get(b, p)) {
            cost += l;
            dsu_unite(a, b, p);
        }
    }
    return cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, pair<ll, ll>>> g(m, {0, {0, 0}}); // вес - вершина 1 - вершина 2
    for (ll i = 0; i < m; ++i) {
        cin >> g[i].second.first >> g[i].second.second >> g[i].first;
        --g[i].second.first;
        --g[i].second.second;
    }
    // for (ll i = 0; i < m; ++i) {
    //     cout << "\n" << g[i].second.first << " " << g[i].second.second << " " << g[i].first << "\n";
    // }
    // first Kruskal, without first edge
    // temporarily assume cost(first edge) > 10**9,
    // then it will not make to spanning tree unleast 
    // there is no spanning tree without this edge
    g[0].first = 1LL << 35;
    ll cost1 = kruskal(n, m, g);
    // second Kruskal, with first edge
    // temporarily assume cost(first edge) = 0,
    // then it will make to spanning tree for sure
    g[0].first = 0;
    ll cost2 = kruskal(n, m, g);
    // answer is cost1 - cost2;
    if (cost1 - cost2 <= 1000000000) {
        cout << cost1 - cost2;    
    } else {
        cout << 1000000000;
    }
    return 0;
}