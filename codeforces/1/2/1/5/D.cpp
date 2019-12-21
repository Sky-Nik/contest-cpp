#include <algorithm>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>

struct Ticket {
    int length;
    std::string number;
};

auto ReadTicket(std::istream& in = std::cin) {
    Ticket ticket;
    in >> ticket.length >> ticket.number;
    return ticket;
}

enum Player {
    kMonocarp = 0,
    kBicarp = 1,
};

auto DetermineWinningPlayer(const Ticket& ticket) {
    int left_half_sum = 0, right_half_sum = 0, left_half_free = 0, right_half_free = 0;

    for (int i = 0; i < (ticket.length >> 1); ++i) {
        if (ticket.number[i] == '?') {
            ++left_half_free;
        } else {
            left_half_sum += ticket.number[i] - '0';
        }
    }

    for (int i = ticket.length >> 1; i < ticket.length; ++i) {
        if (ticket.number[i] == '?') {
            ++right_half_free;
        } else {
            right_half_sum += ticket.number[i] - '0';
        }
    }

    if (left_half_sum + 9 * (left_half_free >> 1) == right_half_sum + 9 * (right_half_free >> 1)) {
        return kBicarp;
    } else {
        return kMonocarp;
    }
}

void PrintPlayer(const Player& winner, std::ostream& out = std::cout) {
    if (winner == kMonocarp) {
        out << "Monocarp";
    } else {
        out << "Bicarp";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto ticket = ReadTicket();
    auto winner = DetermineWinningPlayer(ticket);
    PrintPlayer(winner);

    return 0;
}
