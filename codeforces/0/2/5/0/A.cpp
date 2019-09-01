#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

#define elif else if
#define forn(_i, _n) for(int _i = 0; _i < static_cast<int>(_n); ++_i)
#define fore(_i, _l, _r) for(int _i = _l; _i < _r; ++_i)
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
    int n, c = 0, j = 0;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int neg = count_if(begin(a), end(a), [](int x) { return x < 0; });
    int k = neg ? ((neg + 1) / 2) : 1;
    cout << k << "\n";
    forn(i, n) {
        if (a[i] < 0) {
            if (c < 2) {
                ++c;
            } else {
                cout << i - j << " ";
                --k;
                j = i;
                c = 1;
            }
        }
    }
    if (k) {
        cout << n - j;
    }
    return 0;
}
