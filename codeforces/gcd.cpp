template<typename T>
T gcd(T a, T b) {
    while (a != 0) {
        T tmp = a;
        a = b % a;
        b = tmp;
    }
    return b;
}
