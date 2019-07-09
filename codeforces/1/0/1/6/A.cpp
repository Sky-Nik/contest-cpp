#include <bits/stdc++.h>

using namespace std;

#define elif else if

typedef long long ll;

template<typename T>
inline ostream& operator << (ostream& os, const vector<T>& v) {
    for (const auto& e: v) {
        cout << e << " ";
    }
    cout << "\n";
}

template<typename T>
inline istream& operator >> (istream& is, vector<T>& v) {
    for (auto& e: v) {
        cin >> e;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    cin >> a;
    int c = 0;
    for (int i = 0; i < n; ++i) {
        c += a[i];
        cout << c / m << " ";
        c %= m;
    }
    return 0;
}
