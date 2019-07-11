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
    int n;
    cin >> n;
    map<int, int> mp = {
        {1, 4}, {2, 4}, {3, 4}, {4, 4},
        {5, 4}, {6, 4}, {7, 4}, {8, 4}, 
        {9, 4}, {10, 15}, {11, 4}
    };
    cout << mp[n - 10];
    return 0;
}