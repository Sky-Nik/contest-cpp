#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <istream>
#include <utility>
#include <ostream>
#include <string>
#include <vector>

struct Strings {
    int length;
    std::string first, second;
};

auto ReadStrings(std::istream& in = std::cin) {
    Strings strings;
    in >> strings.length >> strings.first >> strings.second;
    return strings;
}

enum Letters {
    kAb = 0,
    kBa = 1,
};

std::optional<std::vector<std::pair<int, int>>> CalculateMinSwaps(const Strings& strings) {
    std::unordered_map<Letters, std::vector<int>> positions;

    for (int i = 0; i < strings.length; ++i) {
        if (strings.first[i] == 'a' && strings.second[i] == 'b') {
            positions[kAb].push_back(i);
        } else if (strings.first[i] == 'b' && strings.second[i] == 'a') {
            positions[kBa].push_back(i);
        }
    }

    if (positions[kBa].size() + positions[kAb].size() & 1) {
        return std::nullopt;
    } else {
        std::vector<std::pair<int, int>> swaps;

        for (int i = 0; i + 1 < positions[kBa].size(); i += 2) {
            swaps.push_back({positions[kBa][i], positions[kBa][i + 1]});
        }

        for (int i = 0; i + 1 < positions[kAb].size(); i += 2) {
            swaps.push_back({positions[kAb][i], positions[kAb][i + 1]});
        }

        if (positions[kAb].size() & 1) {
            swaps.push_back({positions[kAb].back(), positions[kAb].back()});
            swaps.push_back({positions[kAb].back(), positions[kBa].back()});
        }

        return swaps;
    }
}

void PrintSwaps(const std::optional<std::vector<std::pair<int, int>>>& swaps,
    std::ostream& out = std::cout) {
    if (swaps) {
        out << swaps->size() << "\n";
        for (const auto& swap : *swaps) {
            out << swap.first + 1 << " " << swap.second + 1 << "\n";
        }
    } else {
        out << -1 << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto strings = ReadStrings();
    auto swaps = CalculateMinSwaps(strings);
    PrintSwaps(swaps);

    return 0;
}
