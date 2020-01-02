#include <algorithm>
#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <cmath>

struct Table {
    int side_length;
    std::vector<std::vector<int64_t>> data;
};

auto ReadTable(std::istream& in = std::cin) {
    Table table;
    in >> table.side_length;
    table.data.resize(table.side_length);
    for (auto& row : table.data) {
        row.resize(table.side_length);
        for (auto& number : row) {
            in >> number;
        }
    }
    return table;
}

struct Initial {
    std::vector<int64_t> data;
};

auto FindInitial(const Table& table) {
    Initial initial;
    initial.data.push_back(std::floor(std::sqrt(
        (table.data[0][1] * table.data[0][2] * 1.) / table.data[1][2])));
    initial.data.push_back(std::floor(std::sqrt(
        (table.data[1][0] * table.data[1][2] * 1.) / table.data[0][2])));
    for (int i = 2; i < table.side_length; ++i) {
        initial.data.push_back(std::floor(std::sqrt(
            (table.data[i][0] * table.data[i][1] * 1.) / table.data[0][1])));
    }
    return initial;
}

void PrintInitial(const Initial& initial, std::ostream& out = std::cout) {
    for (const auto& number : initial.data) {
        out << number << " ";
    }
    out << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto table = ReadTable();
    auto initial = FindInitial(table);
    PrintInitial(initial);

    return 0;
}
