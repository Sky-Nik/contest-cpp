#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, ai;
    cin >> n;
    vector<int> c(5, 0);
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        ++c[ai];
    }

    int answer = 0;

    int m12 = min(c[1], c[2]);
    c[0] += m12;
    c[1] -= m12;
    c[2] -= m12;
    c[3] += m12;
    answer += m12;

    if (c[2]) {
        int m23 = c[2] / 3;
        c[0] += m23;
        c[2] -= 3 * m23;
        c[3] += 2 * m23;
        answer += 2 * m23;

        if (c[2] == 2) {
            c[0] += 1;
            c[2] -= 2;
            c[4] += 1;
            answer += 2;
        }

        if (c[2] && c[4]) {
            c[2] -= 1;
            c[3] += 2;
            c[4] -= 1;
            answer += 1;
        }

        if (c[2] && c[3] >= 2) {
            c[0] += 1;
            c[2] -= 1;
            c[3] -= 2;
            c[4] += 1;
            answer += 2;
        }
    }

    if (c[1]) {
        int m13 = c[1] / 3;
        c[0] += 2 * m13;
        c[1] -= 3 * m13;
        c[3] += m13;
        answer += 2 * m13;

        if (c[1] == 2 && c[4]) {
            c[0] += 2;
            c[1] -= 2;
            c[3] += 1;
            c[4] -= 1;
            answer += 2;
        }

        if (c[1] == 2 && c[3] >= 2) {
            c[0] += 2;
            c[1] -= 2;
            c[3] -= 2;
            c[4] += 2;
            answer += 2;
        }

        if (c[1] && c[3]) {
            c[0] += 1;
            c[1] -= 1;
            c[3] -= 1;
            c[4] += 1;
            answer += 1;
        }

        if (c[1] && c[4] >= 2) {
            c[1] -= 1;
            c[3] += 3;
            c[4] -= 2;
            answer += 2;
        }
    }

    if (!c[1] && !c[2]) {
        cout << answer;
    } else {
        cout << -1;
    }

    return 0;
}
