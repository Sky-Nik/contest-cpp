#include <bits/stdc++.h>

using namespace std;

typedef long double ldouble;

template<typename T>
struct point{
    T x;
    T y;
};

template<typename T>
ldouble distance(point<T> p, point<T> q) {
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

int main() {
    point<int> home;
    cin >> home.x >> home.y;
    int n;
    cin >> n;
    point<int> taxi;
    ldouble answer = numeric_limits<ldouble>::infinity();
    for (int i = 0, v; i < n; ++i) {
        cin >> taxi.x >> taxi.y >> v;
        answer = min(answer, distance(taxi, home) / v);
    }
    cout << fixed << setprecision(9) << answer;
    return 0;
}