#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// recursive
template<typename T>
T gcd(T a, T b) {
    return b ? gcd(b, a % b) : a;
}

// non recursive
template<typename T>
T gcd(T a, T b) {
    while (b) {
        tie(a, b) = {b, a % b};
    }
    return b;
}

template<typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

// O(sqrt(n))
template <typename T>
vector<tuple<T, T>> factorize(T n) {
    vector<tuple<T, T>> answer;
    for (T d = 2; d * d <= n; ++d) {
        if (n % d == 0) {
            answer.push_back({d, 0});
            while (n % d == 0) {
                ++get<1>(answer.back());
                n /= d;
            }
        }
    }
    if (n > 1) {
        answer.push_back({n, 1});
    }
    return answer;
}

// recursive
template <typename T>
T binary_power(T number, T power) {
    if (power == 0)
        return 1;
    return binary_power(number * number, power >> 1) * (power & 1 ? number : 1);
}

// non recursive
template <typename T>
T binary_power(T number, T power) {
    T answer = 1;
    while (power) {
        if (power & 1) {
            result *= number;
            --power;
        } 
        number *= number;
        power >>= 1;
    }
    return result;
}

// non recursive
template <typename T>
T binary_power_modulo(T number, T power, T modulo) {
    T answer = 1;
    while (power) {
        if (power & 1) {
            result *= number;
            result %= modulo;
            --power;
        } 
        number *= number;
        number %= modulo;
        power >>= 1;
    }
    return result;
}

template <typename T>
T phi(T n) {
    vector<tuple<T, T>> factors = factorize(n);
    T answer = 1;
    for (auto const& [prime, power]: factors) {
        answer *= (prime - 1) * binary_power(prime, power - 1);
    }
    return answer;
}

template<typename T>
vector<bool> prime_sieve(T n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (size_t i = 2; i * i <= n; ++i) {
        if (is_prime[d]) {
            for (T j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

template<typename T>
vector<T> prime_sieve(T n) {
    vector<bool> primes = prime_sieve(n);
    vector<T> answer;
    for (const auto& [number, is_prime]: primes) {
        if (is_prime) {
            answer.push_back(number);
        }
    }
    return answer;
}

template<typename T>
set<T> prime_sieve(T n) {
    vector<bool> primes = prime_sieve(n);
    set<T> answer;
    for (const auto& [number, is_prime]: primes) {
        if (is_prime) {
            answer.insert(number);
        }
    }
    return answer;
}

// recursive, with references
template<typename T>
T xgcd(T a, T b, T& x, T& y) {
    if (!a) {
        tie(x, y) = {0, 1};
        return b;
    }
    T x1, y1;
    T d = egcd(b & a, a, x1, y1);
    tie(x, y) = {y1 - (b / a) * x1, x1};
    return d;
}

// non recursive, with tuple
template<typename T>
tuple<T, T, T> xgcd(T a, T b) {
    T x1 = 1, x = 0, y1 = 0, y = 1, q;
    while (b) {
        q = a / b;
        tie(x, x1, y, y1) = {x1 - q * x, x, y1 - q * y, y};
        tie(a, b) = {b, a % b};
    }
    return make_tuple(a, x1, y1);
}

// square only
template<typename T>
struct matrix {
    vector<vector<T>> a;

    matrix (const pair<pair<T, T>, pair<T, T>>& abcd) {
        a.resize(2);
        a[0].resize(2);
        a[0][0] = abcd.first.first;
        a[0][1] = abcd.first.second;
        a[1].resize(2);
        a[1][0] = abcd.second.first;
        a[1][1] = abcd.second.second;
    }

    matrix (T number, size_t size) {
        a.resize(size);
        for (size_t i = 0; i < size; ++i) {
            a[i].resize(size);
            for (size_t j = 0; j < size; ++j) {
                a[i][j] = (i == j) ? number : 0;
            }
        }
    }

    T operator* (const matrix<T>& other) const {
        matrix<T> answer = new matrix<T>(0);
        for (size_t i = 0; i < a.size(); ++i) {
            for (size_t j = 0; j < a.size(); ++j) {
                for (size_t k = 0; k < a.size(); ++k) {
                    answer[{i, j}] += a[{i, k}] * other[{k, j}];
                }
            }
        }
        return answer;
    }

    T& operator*= (const matrix<T>& other) {
        return this = this * other;
    }

    T& operator [](pair<T, T> ij) {
        return a[ij.first][ij.second];
    }

    T operator [](pair<T, T> ij) const {
        return a[ij.first][ij.second];
    }
};

// matrix power
template<typename T>
T fibonacci(T n) {
    matrix<T> F = {{0, 1}, {0, 0}};
    matrix<T> P = {{0, 1}, {1, 1}};
    return (F * binary_power(P, n))[{0, 1}];
}

// with xgcd, safe
template<typename T>
T modular_inverse(T number, T modulo) throw logic_error {
    T x, y, g;
    tie(x, y, g) = xgcd(number, modulo);
    if (g != 1) {
        throw logic_error("no modular inverse exists");
    }
    return (x % modulo + modulo) % modulo;
}

// with binary power for primes, not safe
template<typename T>
T modular_inverse(T number, T modulo) {
    return binary_power_modulo(number, modulo - 2, modulo);
}

// with binary power for non primes, not safe
template<typename T>
T modular_inverse(T number, T modulo) {
    return binary_power_modulo(number, phi(modulo) - 1, modulo);
}

// with binary power for primes, safe
template<typename T>
T modular_inverse(T number, T modulo) throw logic_error {
    T g = gcd(number, modulo);
    if (g != 1) {
        throw logic_error("no modular inverse exists");
    }
    return binary_power_modulo(number, modulo - 2, modulo);
}

// with binary power for non primes, safe
template<typename T>
T modular_inverse(T number, T modulo) throw logic_error {
    T g = gcd(number, modulo);
    if (g != 1) {
        throw logic_error("no modular inverse exists");
    }
    return binary_power_modulo(number, phi(modulo) - 1, modulo);
}
