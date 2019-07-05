#include <bits/stdc++.h>
using namespace std;
int n, m;
const int MAXN = 10 + 1;
int a[MAXN], b[MAXN];
int main() {
    cin >> n >> m;
    int m1 = numeric_limits<int>::max(), 
        m2 = numeric_limits<int>::max(), 
        m3 = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m1 = min(m1, a[i]);
    }
    for (int j = 0; j < m; ++j) {
        cin >> b[j];
        m2 = min(m2, b[j]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i] == b[j]) {
                m3 = min(m3, a[i]);
            }
        }
    }
    if (m3 != numeric_limits<int>::max()) {
        cout << m3;
    } else {
        cout << min(m1, m2) << max(m1, m2);
    }

    return 0;
}