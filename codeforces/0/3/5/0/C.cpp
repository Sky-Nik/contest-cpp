#include <bits/stdc++.h>
using namespace std;
#define forn(_forn_i, _forn_n) for (int _forn_i = 0; _forn_i < _forn_n; ++_forn_i)

int n, k;
const int kMaxN = 100'000;

struct p {
    int x, y;

    bool operator<(const p& r) {
        return abs(x) + abs(y) < abs(r.x) + abs(r.y);
    }
};

p ps[kMaxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    forn(i, n) cin >> ps[i].x >> ps[i].y;
    sort(ps, ps + n);
    forn(i, n) {
        if (ps[i].x) k += 2;
        if (ps[i].y) k += 2;
    }
    cout << k + (n << 1) << "\n";
    forn(i, n) {
        if (ps[i].x > 0) cout << "1 " << ps[i].x << " R\n";
        if (ps[i].x < 0) cout << "1 " << -ps[i].x << " L\n";
        if (ps[i].y > 0) cout << "1 " << ps[i].y << " U\n";
        if (ps[i].y < 0) cout << "1 " << -ps[i].y << " D\n";
        cout << "2\n";
        if (ps[i].x > 0) cout << "1 " << ps[i].x << " L\n";
        if (ps[i].x < 0) cout << "1 " << -ps[i].x << " R\n";
        if (ps[i].y > 0) cout << "1 " << ps[i].y << " D\n";
        if (ps[i].y < 0) cout << "1 " << -ps[i].y << " U\n";
        cout << "3\n";
    }
    return 0;
}
