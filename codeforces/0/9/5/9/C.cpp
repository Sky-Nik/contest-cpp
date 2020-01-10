#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n;
    cin >> n;

    if (n > 5) {
        cout << 1 << " " << 2 << "\n";
        cout << 2 << " " << 3 << "\n";
        cout << 2 << " " << 4 << "\n";
    
        for (int i = 5; i < n + 1; ++i)
            cout << 1 << " " << i << "\n";
    } else {
        cout << "-1\n";
    }
  
    for (int i = 1; i < n; ++i)
        cout << i << " " << i + 1 << "\n";

    return 0;
}