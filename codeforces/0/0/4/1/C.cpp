#include <algorithm>
#include <iostream>
#include <string>
#include <stack>

// rewrite these two into one
bool TopIsDot(std::stack<char>* stack) {
    char t1 = stack->top();
    stack->pop();
    char t2 = stack->top();
    stack->pop();
    char t3 = stack->top();
    bool top_is_dot = t3 == 'd' && t2 == 'o' && t1 == 't';
    stack->push(t2);
    stack->push(t1);
    return top_is_dot;
}

bool TopIsAt(std::stack<char>* stack) {
    char t1 = stack->top();
    stack->pop();
    char t2 = stack->top();
    bool top_is_at = t2 == 'a' && t1 == 't';
    stack->push(t1);
    return top_is_at;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string spelled_email;
    std::cin >> spelled_email;

    int n = spelled_email.length();

    bool has_at = false;

    std::stack<char> written_email;
    for (int i = 0; i < n; ++i) {
        written_email.push(spelled_email[i]);

        if (written_email.size() > 3 && i != n - 1 && TopIsDot(&written_email)) {
            written_email.pop();
            written_email.pop();
            written_email.pop();
            written_email.push('.');
        }

        if (!has_at && written_email.size() > 2 && TopIsAt(&written_email)) {
            written_email.pop();
            written_email.pop();
            written_email.push('@');
            has_at = true;
        }
    }

    std::string written_email_;
    while (!written_email.empty()) {
        written_email_ += written_email.top();
        written_email.pop();
    }

    std::reverse(written_email_.begin(), written_email_.end());

    std::cout << written_email_;

    return 0;
}