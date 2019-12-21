#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <istream>
#include <ostream>
#include <numeric>
#include <vector>

auto ReadSequence(std::istream& in = std::cin) {
    int length;
    in >> length;
    std::vector<int> sequence(length);
    for (auto& elem : sequence) {
        in >> elem;
    }
    return sequence;
}

struct NegativePositiveProducts {
    int64_t negative_products, positive_products;
};

enum ProductSign {
    kNegative = 0,
    kPositive = 1,
};

NegativePositiveProducts CountNegativePositiveProducts(const std::vector<int>& sequence) {
    std::unordered_map<ProductSign, std::vector<int>> products_signs;
    products_signs[kNegative] = {0};
    products_signs[kPositive] = {0};
    for (const auto& elem : sequence) {
        if (elem < 0) {
            auto tmp = products_signs[kNegative].back();
            products_signs[kNegative].push_back(products_signs[kPositive].back() + 1);
            products_signs[kPositive].push_back(tmp);
        } else {
            products_signs[kPositive].push_back(products_signs[kPositive].back() + 1);
            products_signs[kNegative].push_back(products_signs[kNegative].back());
        }
    }

    return {
        std::accumulate(products_signs[kNegative].begin(), products_signs[kNegative].end(), 0LL),
        std::accumulate(products_signs[kPositive].begin(), products_signs[kPositive].end(), 0LL)
    };
}

void PrintNegativePositiveProducts(const NegativePositiveProducts& negative_positive_products,
    std::ostream& out = std::cout) {
    out << negative_positive_products.negative_products << " "
        << negative_positive_products.positive_products << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto sequence = ReadSequence();
    auto negative_positive_products = CountNegativePositiveProducts(sequence);
    PrintNegativePositiveProducts(negative_positive_products);

    return 0;
}
