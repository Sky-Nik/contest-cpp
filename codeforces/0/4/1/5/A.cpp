#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
#define sum(a) accumulate(begin(a), end(a), 0ll)

template<typename T>
inline istream& operator >> (istream& is, vector<T>& v) {
    for (auto& e: v) {
        cin >> e;
    }
    return is;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> b(m);
    cin >> b;
    vector<int> answer(n + 1, -1);
    for (auto i: b) {
        for (int j = i; j <= n; ++j) {
            if (answer[j] == -1) {
                answer[j] = i;
            } else {
                break;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << answer[i] << " ";
    }
    return 0;
}