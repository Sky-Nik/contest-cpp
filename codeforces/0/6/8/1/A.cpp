#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string handle;
    bool good = false;
    for (int i = 0, before, after; i < n; ++i) {
        cin >> handle >> before >> after;
        if (after > before && before >= 2400) {
            good = true;
        }
    }
    if (good) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}