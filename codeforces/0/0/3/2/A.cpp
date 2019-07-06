#include <bits/stdc++.h>
using namespace std;
int n, d;
const int MAXN = 1000 + 100;
int a[MAXN];
int main() {
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i != j) && abs(a[i] - a[j]) <= d) {
                ++answer;
            }
        }
    }
    cout << answer;
    return 0;
}