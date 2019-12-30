#include <iostream>
#include <string>
#include <stack>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string upper_signs;
    std::cin >> upper_signs;

    std::stack<char> signs_stack;
    for (const auto& sign : upper_signs) {
        if (!signs_stack.empty() && signs_stack.top() == sign) {
            signs_stack.pop();
        } else {
            signs_stack.push(sign);
        }
    }

    if (signs_stack.empty()) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }

    return 0;
}