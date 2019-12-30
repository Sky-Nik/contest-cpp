#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int valence_a, valence_b, valence_c;
    std::cin >> valence_a >> valence_b >> valence_c;

    bool possible =
        (valence_a + valence_b - valence_c >= 0) && ((valence_a + valence_b - valence_c) % 2 == 0) &&
        (valence_b + valence_c - valence_a >= 0) && ((valence_b + valence_c - valence_a) % 2 == 0) &&
        (valence_c + valence_a - valence_b >= 0) && ((valence_c + valence_a - valence_b) % 2 == 0);

    if (possible) {
        int num_ab_connections = (valence_a + valence_b - valence_c) / 2,
            num_bc_connections = (valence_b + valence_c - valence_a) / 2,
            num_ca_connections = (valence_c + valence_a - valence_b) / 2;

        std::cout <<
            num_ab_connections << " " <<
            num_bc_connections << " " <<
            num_ca_connections << "\n";
    } else {
        std::cout << "Impossible\n";
    }

    return 0;
}