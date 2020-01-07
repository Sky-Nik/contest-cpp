#include <algorithm>
#include <iostream>
#include <istream>
#include <ostream>
#include <vector>

struct Query {
    int data;  // TODO
};

auto ReadQuery(std::istream& in_stream = std::cin) {
    Query query;
    in_stream >> query.data;  // TODO
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
    int data;  // TODO
};

auto ProcessQuery(const Query& query) {
    Answer answer;
    answer.data = query.data;  // TODO
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
    out_stream << answer.data;  // TODO
}

auto PrintAnswers(const std::vector<Answer>& answers, std::ostream& out_stream = std::cout) {
    for (const auto& answer : answers) {
        PrintAnswer(answer);
        out_stream << "\n";
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
