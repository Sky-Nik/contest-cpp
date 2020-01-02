#include <algorithm>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <vector>

struct Cards {
    int num_cards;
    std::string letters;
};

auto ReadCards(std::istream& in = std::cin) {
    Cards cards;
    in >> cards.num_cards >> cards.letters;
    return cards;
}

struct MaxBinaryNumber {
    std::vector<int> digits;
};

auto DetermineMaxBinaryNumber(const Cards& cards) {
    MaxBinaryNumber max_binary_number;
    std::vector<int> zeros(std::count(cards.letters.begin(), cards.letters.end(), 'z'), 0);
    std::vector<int> ones(std::count(cards.letters.begin(), cards.letters.end(), 'n'), 1);
    ones.insert(ones.end(), zeros.begin(), zeros.end());
    max_binary_number.digits = ones;
    return max_binary_number;
}

void PrintMaxBinaryNumber(const MaxBinaryNumber& max_binary_number,
    std::ostream& out = std::cout) {
    for (const auto& digit : max_binary_number.digits) {
        out << digit << " ";
    }
    out << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto cards = ReadCards();
    auto max_binary_number = DetermineMaxBinaryNumber(cards);
    PrintMaxBinaryNumber(max_binary_number);

    return 0;
}
