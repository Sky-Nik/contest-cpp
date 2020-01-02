// #include <algorithm>
// #include <iostream>
// #include <istream>
// #include <ostream>
// #include <vector>
// #include <string>

// auto ReadString(std::istream& in = std::cin) {
//     std::string s;
//     in >> s;
//     return s;
// }

// enum Player {
//     kMike = 0,
//     kAnn = 1
// };

// struct Winners {
//     std::vector<Player> data;
// };

// auto FindWinners(const std::string& s) {
//     Winners winners;
//     // TODO
//     return winners;
// }

// void PrintWinners(const Winners& winners, std::ostream& out = std::cout) {
//     for (const auto& winner : winners.data) {
//         if (winner == kMike) {
//             out << "Mike" << "\n";
//         } else {
//             out << "Ann" << "\n";
//         }
//     }
// }

// int main() {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(nullptr);

//     auto s = ReadString();
//     auto winners = FindWinners(s);
//     PrintWinners(winners);

//     return 0;
// }
