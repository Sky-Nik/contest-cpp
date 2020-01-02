#include <algorithm>
#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <string>

struct Query {
    int num_pin_codes;
    std::vector<std::string> pin_codes;
};

auto ReadQuery(std::istream& in_stream = std::cin) {
    Query query;

    in_stream >> query.num_pin_codes;
    query.pin_codes.resize(query.num_pin_codes);
    for (auto& pin_code : query.pin_codes) {
        in_stream >> pin_code;    
    }

    return query;
}

auto ReadQueries(std::istream& in_stream = std::cin) {
    int num_queries;
    in_stream >> num_queries;

    std::vector<Query> queries(num_queries);
    for (auto& query : queries) {
        query = ReadQuery(in_stream);
    }

    return queries;
}

struct Answer {
    int num_changes;
    std::vector<std::string> pin_codes;
};

auto ProcessQuery(const Query& query) {
    Answer answer;
    answer.num_changes = 0;
    answer.pin_codes = query.pin_codes;
    for (int i = 0; i < query.num_pin_codes; ++i) {
        for (int j = i + 1; j < query.num_pin_codes; ++j) {
            if (answer.pin_codes[i] == answer.pin_codes[j]) {
                ++answer.num_changes;
                bool flag = false;
                for (int k = 0; k < 4; ++k) {
                    bool flag_d;
                    for (int d = 0; d < 10; ++d) {
                        flag_d = true;
                        answer.pin_codes[i][k] = d + '0';
                        for (int l = 0; l < query.num_pin_codes; ++l) {
                            flag_d &= i == l || answer.pin_codes[i] != answer.pin_codes[l];
                        }
                        if (flag_d) {
                            break;
                        } else {
                            answer.pin_codes[i][k] = query.pin_codes[i][k];
                        }
                    }
                    flag |= flag_d;
                    if (flag) {
                        break;
                    }
                }
            }
        }
    }

    return answer;
}

auto ProcessQueries(const std::vector<Query>& queries) {
    std::vector<Answer> answers(queries.size());

    for (int i = 0; i < queries.size(); ++i) {
        answers[i] = ProcessQuery(queries[i]);
    }

    return answers;
}

auto PrintAnswer(const Answer& answer, std::ostream& out_stream = std::cout) {
    out_stream << answer.num_changes << "\n";
    for (const auto& pin_code : answer.pin_codes) {
        out_stream << pin_code << "\n";
    }
}

auto PrintAnswers(const std::vector<Answer>& answers, std::ostream& out_stream = std::cout) {
    for (const auto& answer : answers) {
        PrintAnswer(answer);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto queries = ReadQueries();
    auto answers = ProcessQueries(queries);
    PrintAnswers(answers);

    return 0;
}
