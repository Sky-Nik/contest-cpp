#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(begin(a), end(a));
    if (a[n - 1] >= a[n - 2] + a[n - 3]) {
        cout << "NO";
    } else {
        cout << "YES\n";
        cout << a[n - 2] << " " << a[n - 1] << " " << a[n - 3];
        for (int i = 0; i < n - 3; ++i) {
            cout << " " << a[i];
        }
    }
    return 0;
}