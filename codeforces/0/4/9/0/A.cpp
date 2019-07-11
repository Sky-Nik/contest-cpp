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

template<typename T>
T min_(T t) {
    return t;
}

template<typename T, typename... Args>
T min_(T t, Args... args) {
    return min(t, min_(args...));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> t1, t2, t3;
    int ti;
    forn(i, n) {
        cin >> ti;
        if (ti == 1) {
            t1.push_back(i + 1);
        } elif (ti == 2) {
            t2.push_back(i + 1);
        } else {
            t3.push_back(i + 1);
        }
    }
    int w = min_(t1.size(), t2.size(), t3.size());
    cout << w << "\n";
    forn(i, w) {
        cout << t1[i] << " " << t2[i] << " " << t3[i] << "\n";
    }
    return 0;
}