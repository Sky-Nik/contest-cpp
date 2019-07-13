#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, l, r) for(int i = l; i < r; ++i)
#define sum(a) accumulate(begin(a), end(a), 0ll)

template<typename T>
inline istream& operator >> (istream& is, vector<T>& v) {
    for (auto& e: v) {
        cin >> e;
    }
    return is;
}

char cat(int x) {
    if (x % 4 == 0) {
        return 'D';
    } elif (x % 4 == 1) {
        return 'A';
    } elif (x % 4 == 2) {
        return 'C';
    } else {
        return 'B';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    cin >> x;
    char best_cat = 'D';
    int best_a = -1;
    forn(a, 3) {
        char cur_cat = cat(x + a);
        if (cur_cat < best_cat) {
            best_cat = cur_cat;
            best_a = a;
        }
    }
    cout << best_a << " " << best_cat;
    return 0;
}