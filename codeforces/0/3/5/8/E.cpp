#include <bits/stdc++.h>
using namespace std;

struct vertex {
    int r, c;
    size_t i;
};

bool cmp_r(const vertex& v, const vertex& u) {
    return make_pair(v.r, v.c) < make_pair(u.r, u.c);
}

bool cmp_c(const vertex& v, const vertex& u) {
    return make_pair(v.c, v.r) < make_pair(u.c, u.r);
}

bool euler(const vector<vector<int>>& g) {
    vector<bool> used(g.size(), false);
    queue<int> q;
    q.push(0);
    used[0] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u: g[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
            }
        }
    }

    bool connected = true;
    for (auto ui: used)
        connected &= ui;
    if (!connected)
        return false;

    int is_euler = 0;
    for (auto u: g)
        is_euler += u.size() % 2; 
    return is_euler == 0 || is_euler == 2;
}

bool solve(const vector<vector<int>>& a, int n, int m, int k) {
    int ro = -1, co = -1;
    for (int r = 0; r < n && ro == -1; ++r) {
        for (int c = 0; c < m && co == -1; ++c) {
            if (a[r][c]) {
                ro = r;
                co = c;
            }
        }
    }

    vector<vertex> vs;
    for (int r = 0; r < n; ++r)
        if ((r - ro) % k == 0)
            for (int c = 0; c < m; ++c)
                if ((c - co) % k == 0 && a[r][c])
                    vs.push_back({r, c, vs.size()});

    vector<vector<int>> b(n, vector<int>(m, 0)), g(vs.size());

    sort(vs.begin(), vs.end(), cmp_r);
    for (int i = 0; i + 1 < vs.size(); ++i) {
        int j = i + 1;

        if (vs[j].r == vs[i].r && vs[j].c - vs[i].c == k) {
            int r = vs[i].r;
            bool edge = true;

            for (int c = vs[i].c; c <= vs[j].c; ++c)
                edge &= a[r][c];

            if (edge) {
                for (int c = vs[i].c; c <= vs[j].c; ++c)
                    b[r][c] = a[r][c];

                g[vs[i].i].push_back(vs[j].i);
                g[vs[j].i].push_back(vs[i].i);
            }
        }
    }

    sort(vs.begin(), vs.end(), cmp_c);
    for (int i = 0; i + 1 < vs.size(); ++i) {
        int j = i + 1;

        if (vs[i].c == vs[j].c && vs[j].r - vs[i].r == k) {
            int c = vs[i].c;
            bool edge = true;

            for (int r = vs[i].r; r <= vs[j].r; ++r)
                edge &= a[r][c];

            if (edge) {
                for (int r = vs[i].r; r <= vs[j].r; ++r)
                    b[r][c] = a[r][c];
    
                g[vs[i].i].push_back(vs[j].i);
                g[vs[j].i].push_back(vs[i].i);
            }
        }
    }

    bool extra = false;
    for (int r = 0; r < n; ++r)
        for (int c = 0; c < m; ++c)
            extra |= a[r][c] != b[r][c];
    if (extra)
        return false;

    return euler(g);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (auto& r: a) for (auto& c: r) cin >> c;
    
    int k_max = 0;

    for (int r = 0; r < n; ++r) {
        int cur = 0;

        for (int c = 0; c < m; ++c) {
            if (a[r][c]) {
                ++cur;
            } else {
                k_max = max(k_max, cur);
                cur = 0;
            }
        }

        k_max = max(k_max, cur);
    }

    for (int c = 0; c < m; ++c) {
        int cur = 0;

        for (int r = 0; r < n; ++r) {
            if (a[r][c]) {
                ++cur;
            } else {
                k_max = max(k_max, cur);
                cur = 0;
            }
        }

        k_max = max(k_max, cur);
    }

    --k_max;
    // cout << k_max << "\n";
    
    bool found = false;
    for (int k = 2; k <= k_max; ++k) {
        if (!(k_max % k)) {
            if (solve(a, n, m, k)) {
                cout << k << " ";
                found = true;
            }
        }
    }

    if (!found) {
        cout << -1;
    }

    return 0;
}
