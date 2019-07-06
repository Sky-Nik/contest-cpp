#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXU = 10;

bool check(vector<int>& f) {
    int u = -1;
    for (int i = 0; i < MAXU; ++i) {
        if (f[i] > 0) {
            if (u == -1) {
                u = f[i]; 
            } else if (u != f[i]) {
                return false;
            }
        }
    }
    return true;
}

bool is_valid(vector<int>& f) {
    for (int i = 0; i < MAXU; ++i) {
        if (f[i] > 0) {
            --f[i];
            if (check(f)) {
                ++f[i];
                return true;
            }
            ++f[i];
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> u(n);
    vector<int> f(MAXU, 0);
    int max_x = 0;
    for (int i = 0; i < n; ++i) {
        cin >> u[i];
        --u[i];
        ++f[u[i]];
        if (is_valid(f)) {
            max_x = i + 1;
        }
    }
    cout << max_x;
    return 0;
}