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
    vector<int> before(n), after(n);
    forn(i, n) {
        cin >> before[i] >> after[i];
    }
    bool rated = false, maybe = true;
    forn(i, n) {
        if (before[i] != after[i]) {
            rated = true;
        }
    }
    if (rated) {
        cout << "rated";
    } else {
        forn(i, n) {
            for (int j = i; j < n; ++j) {
                if (before[i] < before[j]) {
                    maybe = false;
                }
            }
        }
        if (!maybe) {
            cout << "unrated";
        } else {
            cout << "maybe";
        }
    }
    return 0;
}