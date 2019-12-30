#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num_magnets;
    std::cin >> num_magnets;

    std::vector<std::string> magnets(num_magnets);
    for (auto& magnet : magnets) {
        std::cin >> magnet;
    }

    int island_counter = 1;

    for (int i = 0; i + 1 < num_magnets; ++i) {
        if (magnets[i] != magnets[i + 1]) {
            ++island_counter;
        }
    }

    std::cout << island_counter << "\n";

    return 0;
}