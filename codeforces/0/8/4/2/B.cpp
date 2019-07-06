#include <bits/stdc++.h>
using namespace std;

typedef long double ldouble;

template<typename T>
struct point{
    T x;
    T y;
};

typedef long double ldouble;

template<typename T>
ldouble distance(point<T> p, point<T> q) {
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

template<typename T>
struct disk{
    point<T> o;
    T r;
};

template<typename T>
struct annulus{
    point<T> o;
    T r;
    T R;
};

template<typename T>
bool is_in(disk<T> d, annulus<T> a) {
    ldouble od = distance(d.o, a.o);
    return (d.r + a.r <= od) && (od + d.r <= a.R);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, d;
    cin >> r >> d;
    annulus<int> a{{0, 0}, r - d, r};
    int n;
    cin >> n;
    int ans = 0;
    disk<int> di;
    for (int i = 0, xi, yi, ri; i < n; ++i) {
        cin >> di.o.x >> di.o.y >> di.r;
        if (is_in(di, a)) {
            ++ans;
        }
    }
    cout << ans;
    return 0;
}
