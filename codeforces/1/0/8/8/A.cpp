#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;

    bool possible = false;

    int answer_a, answer_b; 

    for (int b = 1; b <= x; ++b) {
        for (int a = b; a <= x; a += b) {
            if (a * b > x) {
                possible = true;
                answer_a = a;
                answer_b = b;
            }
        }
    }

    if (possible)
        cout << answer_a << " " << answer_b;
    else
        cout << -1;

    return 0;
}