#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t --> 0) {
        string s;
        cin >> s;

        int answer = 1, current = 1;
    
        for (auto c : s) {
            if (c == 'L') {
                answer = max(answer, ++current);
            } else {
                current = 1;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
