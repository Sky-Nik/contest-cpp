#include <algorithm>
#include <iostream>
#include <istream>
#include <ostream>
#include <vector>

struct Input {
    int length;
    std::vector<int> data;
};

auto ReadInput(std::istream& in = std::cin) {
    Input input;
    in >> input.length;
    input.data.resize(input.length);
    for (auto& elem : input.data) {
        in >> elem;
    }
    return input;
}

struct Answer {
    std::vector<int> data;
};

auto FindAnswer(const Input& input) {
    Answer answer;
    // TODO
    return answer;
}

void PrintAnswer(const Answer& answer, std::ostream& out = std::cout) {
    for (const auto& elem : answer.data) {
        out << elem << " ";
    }
    out << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto input = ReadInput();
    auto answer = FindAnswer(input);
    PrintAnswer(answer);

    return 0;
}
