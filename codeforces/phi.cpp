#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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
    if (n > 1)
        answer.push_back({n, 1});
    return answer;
}

template <typename T>
T binary_power(T number, T power) {
    if (power == 0)
        return 1;
    return binary_power(number * number, power >> 1) * (power & 1 ? number : 1);
}

template <typename T>
T phi(T n) {
    vector<tuple<T, T>> factors = factorize(n);
    T answer = 1;
    for (auto const& [prime, power]: factors) 
        answer *= (prime - 1) * binary_power(prime, power - 1);
    return answer;
}

int main() {
    for (int i = 1; i < 100; ++i)
        cout << "phi(" << i << ") = " << phi(i) << "\n";
    for (ll i = 10000000000; i < 10000000100; ++i)
        cout << "phi(" << i << ") = " << phi(i) << "\n";
    return 0;
}