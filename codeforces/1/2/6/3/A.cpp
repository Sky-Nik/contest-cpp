#include <algorithm>
#include <iostream>
#include <istream>
#include <ostream>
#include <vector>

struct Query {
    int num_red_candies, num_green_candies, num_blue_candies;
};

auto ReadQuery(std::istream& in_stream = std::cin) {
    Query query;

    in_stream >> query.num_red_candies >> query.num_green_candies >> query.num_blue_candies;

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
    int max_eaten_candies;
};

auto ProcessQuery(const Query& query) {
    Answer answer;

    answer.max_eaten_candies = std::min(
        std::min(
            query.num_red_candies + query.num_green_candies,
            query.num_green_candies + query.num_blue_candies
        ),
        std::min(
            query.num_blue_candies + query.num_red_candies,
            (query.num_red_candies + query.num_green_candies + query.num_blue_candies) / 2
        )
    );

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
    out_stream << answer.max_eaten_candies;
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
