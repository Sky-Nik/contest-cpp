#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 100000 + 100;
int x[MAXN];
int main() {
    int a, b, c;
    cin >> a >> b >> c >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        if (x[i] > b && x[i] < c) {
            ++answer;
        }
    }
    cout << answer;
    return 0;
}