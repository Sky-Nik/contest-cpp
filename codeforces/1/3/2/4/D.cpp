#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int64_t> d(n);
    for (auto& di : d) {
        cin >> di;
    }

    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        d[i] -= b;
    }

    sort(d.begin(), d.end());

    if (d[0] > 0) {
        cout << (n * 1ll * (n - 1) >> 1);
    } else {
        int64_t answer;
        int left = 0, right = n;

        while (right > left + 1) {
            int middle = (left + right) >> 1;
            if (d[middle] > 0) {
                right = middle;
            } else {
                left = middle;
            }
        }
    
        int position = right;
        answer = (n - position) * 1ll * (n - position - 1) >> 1;
        for (int i = position; i < n; ++i) {
            left = 0;
            if (d[i] + d[0] > 0) {
                answer += position;
            } else {
                while (right > left + 1) {
                    int middle = (left + right) >> 1;
                    if (d[i] + d[middle] > 0) {
                        right = middle;
                    } else {
                        left = middle;
                    }
                }

                answer += position - right;
            }
        }

        cout << answer;
    }

    return 0;
}
