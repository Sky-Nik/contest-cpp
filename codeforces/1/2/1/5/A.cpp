#include <algorithm>
#include <iostream>
#include <istream>
#include <ostream>

struct TeamsCards {
    int first_size, second_size;
    int first_limit, second_limit;
    int num_cards;
};

auto ReadTeamsCards(std::istream& in = std::cin) {
    TeamsCards teams_cards;

    in >> teams_cards.first_size >> teams_cards.second_size
        >> teams_cards.first_limit >> teams_cards.second_limit
        >> teams_cards.num_cards;

    return teams_cards;
}

struct MinMaxRemovedPlayers {
    int min_removed_players, max_removed_players;
};

auto CalculateMinMaxRemovedPlayers(const TeamsCards& teams_cards) {
    MinMaxRemovedPlayers min_max_removed_players;

    min_max_removed_players.min_removed_players = std::max(teams_cards.num_cards
        - teams_cards.first_size * (teams_cards.first_limit - 1)
        - teams_cards.second_size * (teams_cards.second_limit - 1), 0);

    int max_removed_first = std::min(teams_cards.first_size,
        teams_cards.num_cards / teams_cards.first_limit);

    int max_removed_second = std::min(teams_cards.second_size,
        teams_cards.num_cards / teams_cards.second_limit);

    int total_removed_first = max_removed_first + std::min(teams_cards.second_size,
        (teams_cards.num_cards - max_removed_first * teams_cards.first_limit)
        / teams_cards.second_limit);

    int total_removed_second = max_removed_second + std::min(teams_cards.first_size,
        (teams_cards.num_cards - max_removed_second * teams_cards.second_limit) /
        teams_cards.first_limit); 

    min_max_removed_players.max_removed_players =
        std::max(total_removed_first, total_removed_second);
    
    return min_max_removed_players;
}

void PrintMinMaxRemovedPlayers(const MinMaxRemovedPlayers& min_max_removed_players,
    std::ostream& out = std::cout) {
    out << min_max_removed_players.min_removed_players << " "
        << min_max_removed_players.max_removed_players << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto teams_cards = ReadTeamsCards();
    auto min_max_removed_players = CalculateMinMaxRemovedPlayers(teams_cards);
    PrintMinMaxRemovedPlayers(min_max_removed_players);

    return 0;
}
