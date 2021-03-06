#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (auto& xi: x)
        cin >> xi;

    queue<int> q;
    map<int, int> d;
    for (auto xi: x) {
        q.push(xi);
        d[xi] = 0;
    }

    int64_t sd = 0;
    vector<int> y;

    while (!q.empty() && m) {
        int v = q.front();
        q.pop();

        if (d[v]) {
            sd += d[v];
            y.push_back(v);
            --m;
        }

        if (!d.count(v - 1)) {
            d[v - 1] = d[v] + 1;
            q.push(v - 1);
        }

        if (!d.count(v + 1)) {
            d[v + 1] = d[v] + 1;
            q.push(v + 1);
        }
    }

    cout << sd << "\n";

    for (auto yi: y)
        cout << yi << " ";

    return 0;
}
