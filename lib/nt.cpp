#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// recursive
template <typename T>
T gcd (T a, T b) {
    return b ? gcd(b, a % b) : a; 
}

// not recursive
template <typename T>
T gcd (T a, T b) {
    while (b)
        tie(a, b) = make_pair(b, a % b);
    return a;
}

template <typename T>
T lcm (T a, T b) {
    return a / gcd(a, b) * b;
}

// recursive
template <typename T>
T factorial (T n) {
    return n ? n * factorial(n - 1) : 1;
}

// not recursive
template <typename T>
T factorial (T n) {
    T a = 1;
    for (T i = 2; i <= n; ++i) 
        a *= i;
    return a;
}

// lazy precompute
template <typename T>
class Factorial {
private:
    static vector<T> m;
public:
    T operator() (T n) {
        for (T i = size(m); i <= n; ++i) 
            m.push_back(i * m.back());
        return m[n];
    }
};

template <typename T>
vector<T> Factorial<T>::m = {1};

// O(sqrt(n)), all factors, with powers
template <typename T>
vector<pair<T, T>> factorize (T n) {
    vector<pair<T, T>> a;
    for (T i = 2; i * i <= n; ++i) {
        if (n % i == 0) 
            a.push_back({i, 0});
        while (n % i == 0) {
            ++(a.back().second);
            n /= i;
        }
    }
    if (n > 1) 
        a.push_back({n, 1});
    return a;
}

// O(sqrt(n)), all factors, no powers
template <typename T>
vector<T> factorize (T n) {
    vector<T> a;
    for (T i = 2; i * i <= n; ++i) {
        if (n % i == 0) 
            a.push_back(i);
        while (n % i == 0) 
            n /= i;
    }
    if (n > 1) 
        a.push_back(n);
    return a;
}

// O(sqrt(n)), one factor, no power
template <typename T>
T factor (T n) {
    for (T i = 2; i * i <= n; ++i) 
        if (n % i == 0) 
            return i;
    return n;
}

// recursive
template <typename T>
T binom (T n, T k) {
    return (k == 0 || k == n) ? 1 : binom(n - 1, k - 1) + binom(n - 1, k);
}

// lazy precompute
template <typename T>
class Binom {
private:
    static vector<vector<T>> m; // m[i][j] = binom(i + j, j);
public:
    T operator() (T n, T k) {
        for (T i = size(m); i <= n - k; ++i)
            m.push_back({1});
        for (T i = size(m[0]); i <= k; ++i)
            m[0].push_back(1);
        for (T i = 0; i <= n - k; ++i)
            for (T j = size(m[i]); j <= k; ++j)
                m[i].push_back(m[i - 1][j] + m[i][j - 1]);
        return m[n - k][k];
    }
};

template <typename T>
vector<vector<T>> Binom<T>::m = {{1}};

// row-by-row, O(n k) time, O(k) memory
template <typename T>
T binom (T n, T k) {
    vector<T> c(k + 1, 0); c[0] = 1;
    for (T i = 1; i <= n; ++i)
        for (T j = min(k, i); j >= max(0, i - n + k); --j)
            c[j] = c[j - 1] + c[j];
    return c[k];
}

// O(k * division_cost) time, O(1) memory
template <typename T>
T binom (T n, T k) {
    if (k > n - k)
        k = n - k;
    T a = 1;
    for (T i = 0; i < k; ++i)
        a = (a * (n - i)) / (i + 1);
    return a;
}

// recursive
template <typename T>
T catalan (T n) {
    if (!n)
        return 1;
    T a = 0;
    for (T i = 0; i < n; ++i)
        a += catalan(i) * catalan(n - i);
    return a;
}

// lazy precompute
template <typename T>
class Catalan {
private:
    static vector<T> m;
public:
    T operator() (T n) {
        for (T i = size(m); i <= n; ++i) {
            m.push_back(0);
            for (T j = 0; j < i; ++j)
                m[i] += m[j] * m[i - j - 1];
        }
        return m[n];
    }
};

template <typename T>
vector<T> Catalan<T>::m = {1};

// via binom
template <typename T>
T catalan (T n) {
    return binom(n << 1, n) / (n + 1);
}

// recursive
template <typename T>
T xgcd (T a, T b, T& x, T& y) {
    if (!a) {
        tie(x, y) = {0, 1};
        return b;
    }
    T x1, y1;
    T d = gcd(b % a, a, x1, y1);
    tie(x, y) = {y1 - (b / a) * x1, x1};
    return d;
}

// non recursive, with tuple
template<typename T>
tuple<T, T, T> xgcd (T a, T b) {
    T x1 = 1, x = 0, y1 = 0, y = 1, q;
    while (b) {
        q = a / b;
        tie(x, x1, y, y1) = {x1 - q * x, x, y1 - q * y, y};
        tie(a, b) = {b, a % b};
    }
    return {a, x1, y1};
}
