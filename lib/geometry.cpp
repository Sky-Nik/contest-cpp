# define M_PI 3.14159265358979323846 // pi

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
