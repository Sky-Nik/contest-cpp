#include <iostream>

int Reverse(int n) {
    int r = 0;
    while (n) {
        r *= 10;
        r += n % 10;
        n /= 10;
    }
    return r;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::cout << Reverse(n) << "\n";
    }
    return 0;
}
