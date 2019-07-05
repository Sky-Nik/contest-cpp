#include <bits/stdc++.h>
using namespace std;
int n, m, k;
const int MAXN = 100 + 10;
int a[MAXN];
int main() {
    cin >> n >> m >> k;
    --m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int answer = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
        if ((a[i] != 0) && (a[i] <= k)) {
            answer = min(answer, 10 * abs(i - m));
        }
    }
    cout << answer;
    return 0;
}