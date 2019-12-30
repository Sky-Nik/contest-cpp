#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int64_t numerator, denominator;
    std::cin >> numerator >> denominator;

    int64_t resistors_counter = 0;

    while (numerator && denominator) {
        if (numerator > denominator) {
            resistors_counter += numerator / denominator;
            numerator %= denominator;
        } else {
            resistors_counter += denominator/ numerator;
            denominator %= numerator;
        }
    }

    std::cout << resistors_counter;

    return 0;
}