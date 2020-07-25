#include <iostream>

int main() {
    int n;
    while (true) {
        std::cin >> n;
        if (n == 42) {
            break;
        }
        std::cout << n << "\n";
    }
    return 0;
}
