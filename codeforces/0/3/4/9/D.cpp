#include <bits/stdc++.h>
using namespace std;

int n, xi, yi;
int64_t answer = 0;
const int kMaxN = 100'000;
int64_t a[kMaxN], d[kMaxN], s[kMaxN];
bool visited[kMaxN];
vector<int> g[kMaxN];

int64_t gcd(int64_t a, int64_t b) {
    while (a != 0) {
        tie(a, b) = make_pair(b % a, a);
    }
    return b;
}

int64_t lcm(int64_t a, int64_t b) {
    return a * (b / gcd(a, b));
}

void dfs_d(int v = 0) {
    if (!v) {
        for (int i = 0; i < n; ++i) {
            visited[i] = false;
        }
    }

    visited[v] = true;
    int64_t l = 1, k = 0;
    for (int u: g[v]) {
        if (!visited[u]) {
            dfs_d(u);
            l = l == -1 ? -1 : lcm(l, d[u]);
            if (l > 1'000'000'000'000LL) l = -1; 
            ++k;
        }
    }
    d[v] = l == -1 ? -1 : (k ? k * l : 1);
}

void dfs_s(int v = 0) {
    if (!v) {
        for (int i = 0; i < n; ++i) {
            visited[i] = false;
        }
    }

    visited[v] = true;
    int64_t acc = 0, k = 0;
    for (int u: g[v]) {
        if (!visited[u]) {
            dfs_s(u);
            acc += s[u];
            ++k;
        }
    }

    s[v] = k ? acc : a[v];
}

void dfs_m(int v = 0) {
    if (!v) {
        for (int i = 0; i < n; ++i) {
            visited[i] = false;
        }
    }

    visited[v] = true;
    int64_t m = numeric_limits<int64_t>::max(), k = 0, acc = 0;
    for (int u: g[v]) {
        if (!visited[u]) {
            dfs_m(u);
            m = min(m, s[u]);
            acc += s[u];
            ++k;
        }
    }

    if (k) {
        int64_t t = d[v] == -1 ? m + 1 : d[v] / k;
        int64_t x = (m / t) * t;
        answer += acc - k * x;
        s[v] = k * x;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        cin >> xi >> yi;
        --xi;
        --yi;
        g[xi].push_back(yi);
        g[yi].push_back(xi);
    }

    dfs_d();
    dfs_s();
    dfs_m();

    cout << answer;

    return 0;
}
