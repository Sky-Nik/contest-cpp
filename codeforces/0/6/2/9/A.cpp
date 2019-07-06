#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 100 + 10;
bool cake[MAXN][MAXN];
int main() {
    cin >> n;
    char c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c;
            if (c == 'C') {
                cake[i][j] = true;
            } else {
                cake[i][j] = false;
            }
        }
    } 
    int answer = 0;
    for (int v = 0; v < n; ++v) {
        for (int h1 = 0; h1 + 1 < n; ++h1) {
            for (int h2 = h1 + 1; h2 < n; ++h2) {
                answer += cake[h1][v] && cake[h2][v];
            }
        }
    }
    for (int h = 0; h < n; ++h) {
        for (int v1 = 0; v1 + 1 < n; ++v1) {
            for (int v2 = v1 + 1; v2 < n; ++v2) {
                answer += cake[h][v1] && cake[h][v2];
            }
        }
    }
    cout << answer;
    return 0;
}