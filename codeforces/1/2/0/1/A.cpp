#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define forn(i, n) for(int i = 0; i < n; ++i)

template<typename T>
inline istream& operator >> (istream& is, vector<T>& v) {
    for (auto& e: v) {
        cin >> e;
    }
    return is;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> f(m, vector<int>(5, 0));
    forn(in, n) {
        string si;
        cin >> si;
        forn(j, m) {
            ++f[j][si[j] - 'A'];
        }
    }
    int answer = 0;
    forn(i, m) {
        int ai;
        cin >> ai;
        answer += ai * (*max_element(begin(f[i]), end(f[i])));
    }
    cout << answer;
    return 0;
}