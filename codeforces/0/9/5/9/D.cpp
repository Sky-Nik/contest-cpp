#include <bits/stdc++.h>
using namespace std;

const int64_t kMaxP = 2'000'000;

auto prime_sieve(int64_t max_p = kMaxP) {
    vector<bool> is_prime(max_p, true);
    is_prime[0] = is_prime[1] = false;

    for (int64_t divisor = 2; divisor * divisor < max_p; ++divisor)
        if (is_prime[divisor])
            for (int64_t multiplier = divisor * divisor; multiplier < max_p; multiplier += divisor)
               is_prime[multiplier] = false;

    set<int64_t> primes;

    for (int64_t number = 0; number < max_p; ++number)
        if (is_prime[number])
            primes.insert(number);

    return primes;
}

auto prime_divisors(int64_t number) {
    set<int64_t> divisors;

    for (int64_t divisor = 2; divisor * divisor <= number; ++divisor) {
        while (number % divisor == 0) {
            divisors.insert(divisor);
            number /= divisor;
        }
    }

    if (number != 1)
        divisors.insert(number);

    return divisors;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n;
    cin >> n;

    vector<int64_t> a(n);
    for (auto& ai: a)
        cin >> ai;

    auto primes = prime_sieve();

    vector<bool> free(kMaxP, true);

    bool lex_greater = false;

    vector<int64_t> b(n);

    for (int64_t i = 0; i < n; ++i) {
        if (lex_greater) {
            b[i] = *primes.begin();
            primes.erase(b[i]);
        } else {
            b[i] = a[i];

            while (!free[b[i]])
                ++b[i];

            for (int64_t prime: prime_divisors(b[i]))
                for (int64_t multiplier = prime; multiplier < kMaxP; multiplier += prime)
                    free[multiplier] = false;

            for (int64_t prime: prime_divisors(b[i]))
                primes.erase(prime);

            lex_greater |= b[i] > a[i];
        }
    }

    for (auto& bi: b)
        cout << bi << " ";

    return 0;
}