#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> deg(n);
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        --u;
        --v;
        ++deg[u];
        ++deg[v];
    }
    bool possible = true;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 2) {
            possible = false;
        }
    }
    if (possible) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}