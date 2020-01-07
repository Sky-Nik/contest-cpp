#include <bits/stdc++.h>
using namespace std;

typedef pair<int64_t, int> component;
#define weight first 
#define id second

struct edge {
    int from, to;
    int64_t length;
};

class DSU {
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;

        return parent[v] = find_set(parent[v]);
    }

    int union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);

            parent[b] = a;

            if (rank[a] == rank[b])
                ++rank[a];
        }

        return a;
    }

private:
    vector<int> parent, rank;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, p, q;
    cin >> n >> m >> p >> q;

    DSU dsu(n);

    vector<edge> e(m);
    for (auto& ei: e) {
        cin >> ei.from >> ei.to >> ei.length;
        --ei.from; --ei.to;
        dsu.union_sets(ei.from, ei.to);
    }

    vector<int> component_id(n, -1);
    for (int i = 0; i < n; ++i)
        component_id[i] = dsu.find_set(i);

    vector<int64_t> component_weight(n, -1);
    for (int i = 0; i < n; ++i)
        if (i == component_id[i])
            component_weight[i] = 0;
    for (auto ei: e)
        component_weight[component_id[ei.from]] += ei.length;

    set<component> components;
    for (int i = 0; i < n; ++i)
        if (i == component_id[i])  // && component_weight[i] != -1)
            components.insert(make_pair(component_weight[i], i));

    int nc = components.size();
    if (nc < q || nc - q > p) {
        cout <<  "NO";
    } else {
        vector<edge> to_add;

        for (int i = 0; i < nc - q; ++i) {
            auto it1 = components.begin();
            auto it2 = next(it1);

            to_add.push_back({it1->id, it2->id,
                min(1'000'000'000LL, it1->weight + it2->weight + 1)});

            int new_id = dsu.union_sets(it1->id, it2->id);

            components.erase(make_pair(it1->weight, it1->id));
            components.erase(make_pair(it2->weight, it2->id));
            components.insert(make_pair((to_add.back().length << 1) - 1, new_id));
        }
        p -= nc - q;

        int c = -1;
        for (int i = 0; i < n; ++i) {
            component_id[i] = dsu.find_set(i);
            if (component_id[i] != i) {
                c = i;
            }
        }

        if (c == -1 && p) {
            cout << "NO";
        } else {
            for (int i = 0; i < p; ++i)
                to_add.push_back({c, component_id[c], -1});

            cout << "YES\n";
            for (auto ei: to_add) {
                cout << ei.from + 1 << " " << ei.to + 1 << "\n"; 
            }
        }
    }

    return 0;
}
