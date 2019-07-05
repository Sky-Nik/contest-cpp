#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, n, a, b;
    cin >> n >> m;
    double min_kg_cost = numeric_limits<double>::infinity();
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        min_kg_cost = min(min_kg_cost, (1. * a) / b);
    }
    cout << fixed << setprecision(9) << m * min_kg_cost;
    return 0;
}