#include <bits/stdc++.h>
using namespace std;

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

const int MAXN = 100 + 10;
point<int> a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for (int i = 0, x, y; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    double answer = 0;
    for (int i = 1; i < n; ++i) {
        answer += distance(a[i - 1], a[i]);
    }
    cout << fixed << setprecision(9) << k * answer / 50;
    return 0;
}